#include<iostream>
#include<string.h>
#include<cstdint>
#include"SimpleSerial.cpp"
void get_tosnet_value(std::string);

int main(){
SimpleSerial tosnet("/dev/ttyUSB0",115200);

   const std::string default_red   = "0f73311c";
   const std::string default_green = "48c5051c";
   const std::string default_blue  = "88d4319d";
   const std::string default_no    = "c8330120";
   
   tosnet.set_threshold(default_red,'r');
   tosnet.set_threshold(default_green,'g');
   tosnet.set_threshold(default_blue,'b');
   tosnet.set_threshold(default_no,'n');
   
   char ui;
   bool running=true;
   std::string val="";
   int nr=0;
   
  while(1){
	std::cout << "Symbol description: s = stop, calibrate = c, 	r = set thresholds red, g = set thresholds green, b = set thresholds blue, n = set thresholds no_brick\n";
	std::cout << "Write a char: ";
	std::cin >> ui;	
	switch(ui){
	  case 'c':
				std::cout << "Calibrating";
				tosnet.calibrate();
				break;
	  
	  case 's': running = false;
				break;
	  
	  case 'r': std::cout << "Threshold: ";
				std::cin >> val;
		        tosnet.set_threshold(val,ui);
				break;
	  
	  case 'g': std::cout << "Threshold: ";
				std::cin >> val;
		        tosnet.set_threshold(val,ui);
				break;
	  
	  case 'b': std::cout << "Threshold: ";
				std::cin >> val;
		        tosnet.set_threshold(val,ui);
				break;
	  case 'n': std::cout << "Threshold: ";
				std::cin >> val;
		        tosnet.set_threshold(val,ui);
				break;
	  
	  default:	break;
	}
	sleep(1);
  }

return 0;
}