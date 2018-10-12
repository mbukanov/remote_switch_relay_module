all:
	avr-gcc -mmcu=atmega328p -Os ./src/*.c -o ./src/main.o -D F_CPU=16000000
	
	avr-objcopy -j .text -j .data -O ihex ./src/main.o ./src/sensors_for_home.hex
	avrdude -c usbasp -p m328p -P usb -U flash:w:./src/sensors_for_home.hex

clean:
	rm sensors_for_home.hex ./src/*.o
