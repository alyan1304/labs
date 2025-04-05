
#include <iostream>
int main() {
	int x = 1;
	int y = 1;
	int two = 2;
	int m_three = -3;
	int array[20];
	int counter = 0;
	_asm {
	xor ebx, ebx // reg for x
	xor ecx, ecx // counter
	beg1:
		inc ebx
		cmp ebx, 25 // 25 is the most that x can be 
		jge _end
		mov eax, ebx
		imul two // in eax there's 2x
		sub eax, 50 // 2x - 50
		cdq
		idiv m_three // now y is in edx/eax 
		cmp edx, 0
		jnz beg1
		cmp eax, 0 // eax has to be > than 0
		jng beg1
		mov array[ecx*4], ebx
		mov array[ecx*4 + 4], eax
		add ecx, 2 
		jmp beg1
		_end:
			mov counter, ecx
	}
	for (int i = 0; i < counter; i+=2) {
		std::cout << "2*" << array[i] << " + " << "3*" << array[i + 1] << " = 50" << std::endl;

			
	}
}
