#include <iostream>
#include <cmath>

int main() {
	int x;
	std::cin >> x;
	int res1;
	_asm {
		//(x5 + 2 * (x2 – 4) + x) / x3
		mov eax, x
		imul x // õ*x -> edx:eax
		sub eax, 4 // õ*õ-4 -> eax
		mov ebx, 2
		imul ebx // 2*(x*x - 4) -> eax
		add eax, x // +x -> eax
		mov ebx, eax

		mov ecx, 5
		mov eax, 1
		beg1:
		imul x
			loop beg1
			add ebx, eax

			mov eax, 1
			mov ecx, 3
			beg2:
			imul x
			loop beg2
			mov ecx, eax // x3 -> ecx
			mov eax, ebx
			cdq
			idiv ecx
			mov res1, eax
	}
	int res2 = (pow(x, 5) + 2 * (x * x - 4) + x) / pow(x, 3);
		std::cout << res1 << '\n' << res2;
}
