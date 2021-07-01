#include <wiringPi.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>

#define Buttonpin 1

int main(){
	setenv("WIRINGPI_GPIOMEM", "1", 1);
	wiringPiSetup();
	
	pinMode(Buttonpin, INPUT);

	
	while(1){
		if(digitalRead(Buttonpin) == 1){
			std::cout << "Capture\n";
			//Making picture
			system("raspistill -vf -hf -o img.jpg");
			//Sending email
			system("echo \"New visitor\" | mail -A img.jpg -s \"Visitor\" oleh.yelechko.knm.2018@lpnu.ua");

		}
	}
	
  return 0;
}
