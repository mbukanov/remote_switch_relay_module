#include "uart_utils.h"
#include <util/delay.h>
#include <stdio.h>

#define LED_PIN PB0 // for recv indication
#define RELAY_SIGNAL_PIN PB1

struct BluetoothCommands {
	char value;
	char comment[64];
} bt_cmd[] = { 
{
	'1',
	"Power On\n",
}, {
	'0',
	"Power Off\n",
}
};
enum {
	POWER_ON,
	POWER_OFF
};

void LED_blink() {
	PORTB |= (1 << LED_PIN);
	_delay_ms(100);
	PORTB &= ~(1 << LED_PIN);
}

void main(void) {
	uart0_init();
	DDRB |= (1 << LED_PIN) | (1 << RELAY_SIGNAL_PIN);
	while(1) {
		char c = recv_byte();
		LED_blink();
		if ( c ==  bt_cmd[POWER_ON].value) {
			send(bt_cmd[POWER_ON].comment, sizeof(bt_cmd[POWER_ON].comment));
			PORTB |= (1 << RELAY_SIGNAL_PIN);
		} else if ( c == bt_cmd[POWER_OFF].value) {
			send(bt_cmd[POWER_OFF].comment, sizeof(bt_cmd[POWER_OFF].comment));
			PORTB &= ~(1 << RELAY_SIGNAL_PIN);
		}
		_delay_ms(100);
	}
}
