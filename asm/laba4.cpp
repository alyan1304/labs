#include <iostream>
#include <iomanip>




int	main() {
	double pi;
	int last_correct_digits = 0;
	for (int n = 1; n < 10000000; n+=1000) {
		double x = 0;
		int k;
		int one = 1;
		int two = 2;
		int eight = 8;
		int ten = 10;
		int m_one = -1;
		double difference;
		int correct_digits;

		
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

				fld1
				fild ten
				fldpi
				fst pi
				fld x
				fsub st(1), st(0)
				fstp st(0)
				fst difference
				mov ecx, m_one
				loop2:
					inc ecx
					fmul st(0), st(1)
					fcom st(2)
					FSTSW AX
					SAHF
					jb loop2
				mov correct_digits, ecx
				fstp st(0)
				fstp st(0)
				fstp st(0)
				
		}
		
		int digits_difference = correct_digits - last_correct_digits;
		if (correct_digits >=5 && correct_digits % 2 == 1 && digits_difference == 1) 
			std::cout << std::setprecision(18) << n << "\t\t" << x << "\t" << difference << "\t\t" << correct_digits << "\n";
		last_correct_digits = correct_digits;

	}
	std::cout << "pi = " << pi;
}
