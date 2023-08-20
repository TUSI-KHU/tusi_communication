#include <cstdio>
#include <cstdint>

typedef struct {
	int data1;
	int data2;
	unsigned long a;
	int f;
} Payload;

void printHex(const uint8_t* data, size_t length) {
	for (size_t i = 0; i < length; i++) {
		//if (data[i] < 16) {
		//	printf("0");
		//}
		//else {
			printf("%x", data[i]);
		//}
	}
}

void printDex(const Payload* data, size_t length) {
	for (size_t i = 0; i < length; i++) {
		//if (data[i] < 16) {
		//	printf("0");
		//}
		//else {
			printf("%d", data[i]);
		//}
	}
}

int main() {
	Payload pl;
	pl.data1 = 0x4a; //74
	pl.data2 = 0xff; //255
	pl.a = 0xF4240; //1000000
	pl.f = 0xfa; //250

	const uint8_t* buf1 = reinterpret_cast<const uint8_t*>(&pl);
	size_t bufsize = sizeof(pl);

	printf("%u\n", bufsize * 2);
	printHex(buf1, bufsize);
	printf("\n");

	const Payload* buf2 = reinterpret_cast<const Payload*>(buf1);
	printf("%d %d %u %d", buf2->data1, buf2->data2, buf2->a, buf2->f);
}
