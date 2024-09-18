#include <iostream>
#include <cmath>
int main(){
    int k;
    do{
    std::cout << "Input natural k>1" << std::endl;
    std::cin >> k;} while (k <= 1);
    double x;
    std::cout << "Input x" << std::endl;
    std::cin >> x;
    double summand = 1;
    double res = summand;
    int i = 1;
    while (std::fabs(summand)>=(pow(10, -k))){
        summand *= (-(pow(x, 2)/((i+1) *(i + 2))));
        res += summand;
        i+=2;
    }
    std::cout << res << std::endl;
    std::cout << std::fabs((sin(x)/x)-res);
    return 0;
}
