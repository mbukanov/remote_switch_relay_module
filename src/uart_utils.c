#include "uart_utils.h"
#include <util/delay.h>

void uart0_init() {
	UBRR0H = (unsigned char)(BAUD_PRESCALE >> 8);
	UBRR0L = (unsigned char)(BAUD_PRESCALE);
	UCSR0B = (1 << RXEN0) | (1 << TXEN0) ;
	UCSR0C = (1 << USBS0) | (3 << UCSZ00) ;
}

char recv_byte() {
	while ( !(UCSR0A & (1<<RXC0)) );
	return UDR0;
}

void send(unsigned char * bytes, int len) {
	int i = 0;
	for(i = 0; i < len; i++) {
		while ((UCSR0A & (1 << UDRE0)) == 0) {};
		UDR0 = bytes[i];
	}
}


void send_byte(unsigned char byte) {
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = byte;
}
