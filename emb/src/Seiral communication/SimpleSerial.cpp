#include <boost/asio.hpp>

#define red   0b00111111111100000000000000000000
#define green 0b00000000000011111111110000000000
#define blue  0b00000000000000000000001111111111


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

std::string tosnet_command(std::string word){
	std::string input = "";
	writeString(word);
	input = readLine();
	return input;	
	}	

void set_threshold(std::string value, char color){
  std::string command = "r0";
  switch(color){
	case 'r': command.append("0 ");
	case 'g': command.append("1 ");
	case 'b': command.append("2 ");
	case 'n': command.append("3 ");
  }
  command.append(value);
  tosnet_command(command);
}
	
void get_colors(int number = 1){
    std::string input;
	for(int i = 0;i<number;i++){
	  
	input = tosnet_command("r10");
	std::int32_t x = 0;
	std::stringstream ss;
	ss << std::hex << input;
	ss >> x;
	
	int red_val=0,green_val=0,blue_val = 0;
	red_val   = (x & red) >> 20;
	green_val = (x & green) >> 10;
	blue_val  = (x & blue);
	std::cout << "Red: " << red_val << "\tGreen: " << green_val << "\tBlue: " << blue_val << std::endl; 
	}
};
private:
    boost::asio::io_service io;
    boost::asio::serial_port serial;
};