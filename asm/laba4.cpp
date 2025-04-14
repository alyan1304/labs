#include <iostream>
#include <iomanip>




int	main() {
	double pi;
	int precision = 0;
	int newPrecision = 1;
	int one = 1;
	int two = 2;
	int eight = 8;
	int ten = 10;
	int m_one = -1;
	int intPI;
	int intX;
	unsigned short controlWord, newControlWord;
	for (int n = 1; n < 1000000; n++) {
		double x = 0;
		int k;
	
		_asm {
			finit
			mov ecx, n
			fild two
			loop1 :
			mov k, ecx
				fild k
				fmul st(0), st(1)
				fld1
				fsub st(1), st(0)
				fdiv st(0), st(1)
				fmul st(0), st(0)
				fadd x
				fstp x
				fstp st(0)
				loop loop1

				fstp st(0)
				fld x
				fild eight
				fmul st(0), st(1)
				fsqrt
				fstp x
				fstp st(0)

				fldpi
				fst pi
				fld x
				fild ten
				mov ecx, newPrecision
				loop2:
					fmul st(1), st(0)
					fmul st(2), st(0)
					loop loop2
				
				fnstcw controlWord
				mov ax, 0F3Fh
				mov newControlWord, ax
				fldcw newControlWord
				fstp ST(0)
				fistp intX
				fistp intPI
				fldcw controlWord
				
				mov eax, intPI
				CMP eax, intX
				jne _end
				inc precision

				_end:
		}
			if (precision == newPrecision) {
				if (precision >= 5 && precision % 2 == 1) {
					std::cout << std::setprecision(18) << n << "\t\t" << x << "\t" << "\t\t" << newPrecision << "\n";
				}
			++newPrecision;
			}

	}
	std::cout << "pi = " << pi;
}
