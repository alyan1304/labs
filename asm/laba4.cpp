#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

int correctDigits(double num, double pi) {
	std::ostringstream stream1, stream2;
	stream1 << std::fixed << std::setprecision(18) << num;
	stream2 << std::fixed << std::setprecision(18) << pi;
	std::string str1 = stream1.str();
	std::string str2 = stream2.str();
	int count = 0;
	for (int i = 2; i < std::min(str1.length(), str2.length()); ++i) {
		if (str1[i] == str2[i]) {
			++count;
		}
		else {
			break;
		}
	}
	return count;
}


int	main() {
	double pi;
	for (int n = 1; n < 1000000; n+=1000) {
		double x = 0;
		int k;
		int two = 2;
		int eight = 8;
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

				fld x
				fldpi
				fst pi
				fsub st(0), st(1)
				fstp difference
				fstp st(0)

		}
		
		
		correct_digits = correctDigits(x, pi);
		if (correct_digits >= 5 && correct_digits % 2 == 1) 
			std::cout << std::setprecision(18) << n << "\t\t" << x << "\t" << difference << "\t\t" << correct_digits << "\n";
		
	}
	std::cout << "pi = " << pi;
}
