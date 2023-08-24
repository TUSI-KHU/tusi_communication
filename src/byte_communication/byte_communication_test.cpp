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
	//buf1은 Payload 구조체의 첫 번째 바이트의 주소를 가리키게 됩니다. 
	//이 주소로부터 sizeof(Payload)만큼의 바이트를 읽어오면 Payload 구조체의 내용을 바이트 단위로 볼 수 있게 됩니다.
	//통신으로 읽어올 떄는 단순 데이터값만을 읽어옴, 주소값은 읽어보기 불가능 -> 000fa0f4240000ff0004a 값만을 이용하여 대입 
	//-> 0인 부분들을 자른다면? bit shift를 통해 잘라진 것들을 송수신
	size_t bufsize = sizeof(pl);

	printf("%u\n", bufsize * 2);
	printHex(buf1, bufsize);
	printf("\n");

	const Payload* buf2 = reinterpret_cast<const Payload*>(buf1);
	printf("%d %d %u %d", buf2->data1, buf2->data2, buf2->a, buf2->f);
}
