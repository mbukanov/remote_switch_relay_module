all:
	avr-gcc -mmcu=atmega328p -Os *.c -o main.o -D F_CPU=16000000
	
	avr-objcopy -j .text -j .data -O ihex main.o sensors_for_home.hex
	avrdude -c usbasp -p m328p -P usb -U flash:w:sensors_for_home.hex

clean:
	rm sensors_for_home.hex *.o
