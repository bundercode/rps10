

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "RS-232/rs232.h"

int main (int argc, char* argv[]) {

char module_addr = 42; // (*) send to all modules by default
char op_code = 84; // (T) toggle status by default
int com_port = 0; // ttyS0 defult rs232 port
int baudrate = 9600;
char mode[] = {'8','N','1',0};

	if (argc > 1) {
		int arg_n;
		for (arg_n=1; arg_n < argc; ++arg_n) {
			if (strncmp (argv[arg_n], "-n", 2) == 0) {
				if (arg_n +1 < argc) {
					module_addr = (char)argv[arg_n];
				} else {
					// return error
					printf("module_addr flag w/o value\n");
					return(0);
				}
			} else if (strncmp (argv[arg_n], "-0", 2) == 0) {
				printf("change 0\n");
				op_code = 48; //op_code = 0
			} else if (strncmp (argv[arg_n], "-1", 2) == 0) {
				op_code = 49; //op_code = 1
			} else if (strncmp (argv[arg_n], "-c", 2) == 0) {
				if (arg_n +1 < argc) {
					// set com port
					com_port = 0;
				} else {
					// return error
					printf("com_port flag w/o value\n");
					return(0);
				}
			} else {
				// return error
				//printf("invalid args\n");
				//return(0);
			}
		}
	}

// ^=ctrl	^B^X^X^B^X^X(module_addr)(op_code)^M
char cmd_str[] = {2, 24, 24, 2, 24, 24, module_addr, op_code, 13};

if (RS232_OpenComport (com_port, baudrate, mode)) {
	printf ("Can not open comport\n");
	return(0);
}
usleep(100000);

int buf_size;
char buf[4096];

buf_size = RS232_PollComport (com_port, buf, 4095);
buf[buf_size] = 0;
printf("RS232 says: %s\n", (char *)buf);

if (RS232_SendBuf (com_port, cmd_str, strlen(cmd_str)) == -1 ) {
	printf("Send error\n");
	return(0);
}

RS232_CloseComport (com_port);
return(0);
}
