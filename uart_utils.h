#ifndef UART_UTILS
#define UART_UTILS


#include <avr/io.h>

#define USART_BAUDRATE  9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL)))-1)
//#define BAUD_PRESCALE F_CPU/16/USART_BAUDRATE-1

void uart0_init();
char recv_byte();
void send(unsigned char * bytes, int len);
void send_byte(unsigned char byte);

#endif
