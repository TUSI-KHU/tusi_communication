#include <iostream>
#include <cstdio>

int main() {
	unsigned int H1 = 255;
	unsigned int H1H;
	H1H = H1 & 0xFF;
	printf("%x\n", H1H);
	unsigned int H1_ = H1H;
	std::cout << H1 << " " << H1_ << std::endl;

	unsigned int H2 = 65535;
	unsigned int H2H, H2L;
	H2L = H2 & 0xFF;
	H2H = (H2 >> 8) & 0xFF;
	printf("%x %x\n", H2L, H2H);
	unsigned int H2_ = (H2H << 8) + H2L;
	std::cout << H2 << " " << H2_ << std::endl;

	unsigned int H3 = 16777215;
	unsigned int H3H, H3M, H3L;
	H3L = H3 & 0xFF;
	H3M = (H3 >> 8) & 0xFF;
	H3H = (H3 >> 16) & 0xFF;
	printf("%x %x %x\n", H3L, H3M, H3H);
	unsigned int H3_ = (H3H << 16) + (H3M << 8) + H3L;
	std::cout << H3 << " " << H3_ << std::endl;
}
