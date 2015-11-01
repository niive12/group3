#include<iostream>
#include<string.h>
#include<cstdint>
#include"SimpleSerial.cpp"
void get_tosnet_value(std::string);

int main(){
SimpleSerial tosnet("/dev/ttyUSB0",115200);

   char ui;
   bool running=true;
   std::string val="";
   int nr=0;
  while(1){
	std::cout << "Symbol description: s = stop, color values = c, 	r = set thresholds red, g = set thresholds green, b = set thresholds blue, n = set thresholds no_brick\n";
	std::cout << "Write a char: ";
	std::cin >> ui;	
	switch(ui){
	  case 'c': std::cout << "Number of samples: "
				std::cin >> nr;
	            if(nr > 0){
				  tosnet.get_colors(100);
				}else{
				  std::cout << "Number of samples invalid\n";
				}
				break;
	  
	  case 's': running = false;
				break;
	  
	  case 'r': std::cout << "Threshold: ";
				std::cin >> val;
		        tosnet.set_threshold(val,ui);
				break;
	  
	  default:	break;
	}
	sleep(1);
  }

return 0;
}