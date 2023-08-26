#include <iostream>
#include <cstdio>

int main() {
	unsigned int X = 12345678; //BC614E
	unsigned int XL = X & 0xFF;
	unsigned int XM = (X >> 8) & 0xFF;
	unsigned int XH = (X >> 16) & 0xFF;
	printf("%x %x %x", XL, XM, XH);
}
