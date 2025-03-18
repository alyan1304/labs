#include <iostream>
#include <bitset>
#include <cstdint>
#include <iomanip>
int main() {
	unsigned __int16 A1, A2, B1, B2;
	__int16 A3, B3, C1, C2, C3;
	//std::cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3;
	A1 = 1 << 15;
	B1 = 1 << 15;
	A2 = 0xffff;
	B2 = A3 = B3 = 0;

	__asm {
		mov ax, A1
		add ax, B1
		mov C1, ax
		mov ax, A2
		adc ax, B2
		mov C2, ax
		mov ax, A3
		adc ax, B3
		mov C3, ax




	}

	std::cout << std::hex << std::setfill('0') << std::setw(4) << C3 << ' ';
	std::cout << std::hex << std::setfill('0') << std::setw(4) << C2 << ' ';
	std::cout << std::hex << std::setfill('0') << std::setw(4) << C1 << '\n';

	std::cout << std::bitset<16>(C3) << ' ';
	std::cout << std::bitset<16>(C2) << ' ';
	std::cout << std::bitset<16>(C1) << ' ';
}