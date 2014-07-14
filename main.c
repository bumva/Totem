#include "config.h"

__idata byte ll[8][5];
__idata byte hh[8][5];

byte custom_input_action(byte data) {
	if (UART_ON) {
		process_msg_ilpp(data);
		#if PROTEUS
			if (is_msg_ilpp())
		#endif
		return 1;
	}
	return 0;
}

void custom_action() { ack_msg_ilpp(); }

void main() {
	init_at89s();
	
	_dis_num = 7;
	_write_digits(4);
	init_msg_ilpp();
	init_display();
	run_display();
}

