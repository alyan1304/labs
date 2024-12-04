#include <iostream>
#include "stack.h"

int main(){
    Stack stack;
    std::cout << stack.isEmpty() << std::endl;
    stack << 3 << 5;
    std::cout << stack[1] << std::endl;
    Stack stack2;
    std::cout << (stack == stack2) << std::endl;
    std::cout << (stack2 < stack) << std::endl;
    stack2 = stack;
    std::cout << (stack == stack2) << std::endl;
    int a;
    int b;
    stack >> a >> b;
    std::cout << a << std::endl;
    try {
        int c;
        stack >> c;
    } catch(const std::out_of_range& e) {
        std::cerr << "Error occured: " << e.what() << std::endl;
    }
    try {
            std::cout << stack[0] << std::endl;
    } catch(const std::out_of_range& e) {
        std::cerr << "Error occured: " << e.what() << std::endl;
    }
}

