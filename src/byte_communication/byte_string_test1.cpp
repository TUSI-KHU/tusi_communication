#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

//This type cannot read more than length > 2

typedef struct {
	int data1;
	int data2;
	unsigned long a;
	int f;

} Payload;

unsigned int ascii_to_hex(const char* str, size_t size, uint8_t* hex, int h) {
	unsigned int i, high, low;
	for (i = 0; i < size; i += 2) {
		high = (str[i] > '9') ? str[i] - 'A' + 10 : str[i] - '0';
		low = (str[i + 1] > '9') ? str[i + 1] - 'A' + 10 : str[i + 1] - '0';
		hex[h] = (high << 4) | low;
	}
	return h;
}

int main() {
	char str[] = "4A/FF/F4240/FA";
	std::string data_pack[4] = {" "};
	std::string input_str = "";
	uint8_t hex[128] = { 0, };
	uint8_t data[128] = { 0, };
	int n = 0;

	Payload pl;
	pl.data1 = 0x4a; //74
	pl.data2 = 0xff; //255
	pl.a = 0xF4240; //1000000
	pl.f = 0xfa; //250

	Payload pl2;
	pl2.data1 = 0x00; 
	pl2.data2 = 0x00; 
	pl2.a = 0x00; 
	pl2.f = 0x00; 

	printf("%x %x %x %x\n", pl.data1, pl.data2, pl.a, pl.f);
	
	for (char elem : str) {
		if (elem == '/' or elem == '\0') {
			data_pack[n] = input_str;
			const char* c = const_cast<char*>(input_str.c_str());
			ascii_to_hex(c, data_pack[n].length(), hex, n);
			input_str = "";
			n++;
		}
		else {
			input_str += elem;
		}
	}
	pl2.data1 = hex[0]; //74
	pl2.data2 = hex[1]; //255
	pl2.a = hex[2]; //1000000
	pl2.f = hex[3]; //250

	printf("%x %x %x %x\n", pl2.data1, pl2.data2, pl2.a, pl2.f);
	
}
