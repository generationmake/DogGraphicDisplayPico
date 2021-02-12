#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "DogGraphicDisplay.hpp"
#include "ubuntumono_b_16.h"

const uint LED_PIN=25;
const uint BACKLIGHT_PIN=20;

DogGraphicDisplay DOG;

int main(){
	
	bi_decl(bi_program_description("DogGraphicDisplayPico."));
	
	stdio_init_all();
	
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN,GPIO_OUT);
	gpio_init(BACKLIGHT_PIN);
	gpio_set_dir(BACKLIGHT_PIN,GPIO_OUT);
	gpio_put(BACKLIGHT_PIN,1);

//	DOG.begin(14,7,6,0,1,DOGM128);   //CS = 14, 7,6= use Software SPI, A0 = 0, RESET = 1, EA DOGM128-6 (=128x64 dots)
	DOG.begin(14,0,0,0,1,DOGM128);   //CS = 14, 0,0= use Hardware SPI, A0 = 0, RESET = 1, EA DOGM128-6 (=128x64 dots)

	DOG.clear();  //clear whole display
	DOG.string(0,0,UBUNTUMONO_B_16,"RaspberryPi Pico", ALIGN_CENTER); // print text in line 0 at position center

	static int offset=DOG.display_width(); // static variable with the size of the display, so text starts at the right border

	while(1){
		DOG.string(offset,3,UBUNTUMONO_B_16,"Hello to the scrolling World on Pico!"); // print "Hello World" in line 3 at position offset

		offset--; // decrasye offset so text moves to the left
		if(offset<-292) offset=DOG.display_width(); //our text is 232 pixels wide so restart at this value

		gpio_put(LED_PIN,0);
		sleep_ms(20);
		gpio_put(LED_PIN,1);
		sleep_ms(40);
	}
}
