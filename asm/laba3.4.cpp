#include <iostream> 

int main() {
	int num; // int
	int denum; // nat
	do {
		std::cin >> num >> denum;
	} while (denum <= 0);
	_asm {
		mov eax, num
		mov ebx, denum
		cmp eax, 0
		jg _beg
		je _end
		neg eax
		_beg:
		cmp eax, ebx

		jg num_greater
		jl denum_greater
		je _equal

		num_greater:
			sub eax, ebx
			jmp _beg

		denum_greater:
			sub ebx, eax
			jmp _beg

		_equal:
			mov ecx, eax
			mov eax, num
			cdq
			idiv ecx
			mov num, eax
			mov eax, denum
			cdq
			idiv ecx
			mov denum, eax

		_end:
	}
	std::cout << num << "/" << denum;
}