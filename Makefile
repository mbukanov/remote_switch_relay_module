HEX_FILE_PATH=bluetooth_plug.hex
AVR_SRC_PATH=./src/
CPU_FREQ=16000000
OBJ_FILE_PATH=./src/main.o

AVR_GCC_ATMEGA_VER=atmega328p
AVR_DUDE_ATMEGA_VER=m328p


all: build flash

build:
	avr-gcc -mmcu=${AVR_GCC_ATMEGA_VER} -Os ${AVR_SRC_PATH}*.c -o ${OBJ_FILE_PATH} -D F_CPU=${CPU_FREQ}
	avr-objcopy -j .text -j .data -O ihex ${OBJ_FILE_PATH} ${HEX_FILE_PATH}

flash:
	avrdude -c usbasp -p ${AVR_DUDE_ATMEGA_VER} -P usb -U flash:w:${HEX_FILE_PATH}

clean:
	rm ${HEX_FILE_PATH} ${AVR_SRC_PATH}*.o
