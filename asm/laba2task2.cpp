#include <iostream>

int main() {
	unsigned int x;
	std::cin >> x;
	bool res1;
	_asm {
	mov eax, x
	mov ebx, 10
	xor ecx, ecx // в ecx будет кол-во цифр в числе
	beg1:
		inc ecx
		cdq
		div ebx
		cmp eax, 0
		jnz beg1
	mov eax, 1
	beg2:
		mul ebx
		loop beg2
	mov ecx, eax // в ecx степень десятки
	mov eax, x 
	mul x // в eax проверяемое число в квадрате
	cdq
	div ecx // младшие цифры квадрата теперь в edx
	cmp x, edx
	jne _no
	mov res1, 1
	jmp _end
	_no:
		mov res1, 0
	_end:
	
	}
	bool res2 = 0;
	int intPart;
	int degreeOfTen = 1;
	do {
		degreeOfTen *= 10;
		intPart = x / degreeOfTen;
		
	} while (intPart != 0);
	if (x * x % degreeOfTen == x) {
		res2 = 1;
	}
	std::cout << res1 << '\n' << res2;
}
