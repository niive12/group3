#include<iostream>
#include<string.h>
#include<cstdint>
#include"SimpleSerial.cpp"
void get_tosnet_value(std::string);

#define red   0b00111111111100000000000000000000
#define green 0b00000000000011111111110000000000
#define blue  0b00000000000000000000001111111111

int main(){

  std::string ui;
  while(1){
	/*std::cin >> ui;	
	if(ui =="s")
	  break*/;
	sleep(1);
	get_tosnet_value("r10");
  }
  
return 0;
}

void get_tosnet_value(std::string word){;	
	SimpleSerial tosnet("/dev/ttyUSB0",115200);
	std::string input = "";
	tosnet.writeString(word);
	input = tosnet.readLine();
	std::int32_t x = 0;
	std::stringstream ss;
	ss << std::hex << input;
	ss >> x;
	
	int red_val=0,green_val=0,blue_val = 0;
	red_val   = (x & red) >> 20;
	green_val = (x & green) >> 10;
	blue_val  = (x & blue);
	std::cout << "Red: " << red_val << "\tGreen: " << green_val << "\tBlue: " << blue_val << " Input: " << input << "\tHex: " << x << std::endl;
}	
