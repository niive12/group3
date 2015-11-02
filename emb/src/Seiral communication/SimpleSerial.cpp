#include <boost/asio.hpp>

#define red    0b00111111111100000000000000000000
#define green  0b00000000000011111111110000000000
#define blue   0b00000000000000000000001111111111
#define header 0b11000000000000000000000000000000

#define calibrate_nr_samples 10


class SimpleSerial
{
public:
  /**
   * Constructor.
   * \param port device name, example "/dev/ttyUSB0" or "COM4"
   * \param baud_rate communication speed, example 9600 or 115200
   * \throws boost::system::system_error if cannot open the
   * serial device
   */
  SimpleSerial(std::string port, unsigned int baud_rate) 
  : io(), serial(io,port)
  {
	serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
  }
  
  /**
   * Write a string to the serial device.
   * \param s string to write
   * \throws boost::system::system_error on failure
   */
  void writeString(std::string s)
  {
	boost::asio::write(serial,boost::asio::buffer(s.c_str(),s.size()));
  }
  
  /**
   * Blocks until a line is received from the serial device.
   * Eventual '\n' or '\r\n' characters at the end of the string are removed.
   * \return a string containing the received line
   * \throws boost::system::system_error on failure
   */
  std::string readLine()
  {
	char response[9] = {};
	
	boost::asio::read(serial, boost::asio::buffer(response, 9));
	
	return response;
  }
  
  std::string tosnet_command(std::string word,bool read=false){
	std::string input = "";
	writeString(word);
	if(read){
	  input = readLine();
	}
	return input;	
  }	
  
  void set_threshold(std::string value, char color){
	std::string command = "w0";
	switch(color){
	  case 'r': command.append("4 ");break;
	  case 'g': command.append("5 ");break;
	  case 'b': command.append("6 ");break;
	  case 'n': command.append("7 ");break;
	}
	//  std::string a = get_colors(10);
	//  command.append(a);
	command.append(value);
	command.append("\r");
	std::cout << command << std::endl;
	tosnet_command(command);
  }
  
void calibrate(){
	std::string input;
	std::string color;
	int color_nr;
	for(int j = 0;j<4;j++){
	  int red_val=0,green_val=0,blue_val = 0;
	  char dummy;
	  std::string ex;
	  if(j == 0){
		ex = "w04 ";
		std::cout << "\nPut in red block and press y: ";
		std::cin >> dummy;
		std::cout << "\n";
	  }else if(j == 1){
		std::cout << "Put in green block and press y: ";
		sleep(1);
		std::cin >> dummy;
		ex = "w05 "; 
		std::cout << "\n";
	  }else if(j == 2){
		ex = "w06 "; 
		std::cout << "Put in blue block and press y: ";
		std::cin >> dummy;
		std::cout << "\n";
	  }else{
		std::cout << "Remove blocks and press y: ";
		std::cin >> dummy;
		ex = "w07 "; 
	  }
	  for(int i = 0;i<calibrate_nr_samples;i++){
		
		input = tosnet_command("r10",true);
		unsigned int x = 0;
		std::stringstream ss;
		ss << std::hex << input;
		ss >> x;
		
		int temp_1 = (x & red) >> 20;
		int temp_2 = (x & green) >> 10;
		int temp_3 = (x & blue);
		red_val   += temp_1;
		green_val += temp_2;
		blue_val  += temp_3;
		color_nr =  (x & header) >> 30;
		
		switch(color_nr){
		  case 0: color =  "blue";     break;
		  case 1: color =  "red";    	 break;
		  case 2: color =  "green";    break;
		  case 3: color =  "invalid";  break;
		  default: color = ""; break;
		}
		std::cout << "Red: " << temp_1 << "\tGreen: " << temp_2 << "\tBlue: " << temp_3 << " Color detected by decider: " << color <<std::endl; 
		sleep(1);
	  }
	  
	  red_val/=calibrate_nr_samples;
	  green_val/=calibrate_nr_samples;
	  blue_val/=calibrate_nr_samples;
	  std::stringstream stream;
	  stream << std::hex << 0 << 0 << red_val << green_val << blue_val;
	  std::string result( stream.str() );
	  red_val=0;
	  green_val=0;
	  blue_val=0;
	  ex.append(result);
	  std::cout << ex << std::endl;
	}
  };
  
private:
  boost::asio::io_service io;
  boost::asio::serial_port serial;
};