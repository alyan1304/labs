#include "myStack.h"
#include <string>
#include <cctype>
using std::string;
using std::cin;
using std::cout;



class Calc {
public:
    double getResult(string expr) {
        process(expr);
        while (!operations.isEmpty()) {
            calculate(numbers, operations);
        }
        double result;
        numbers >> result;
        return result;
    }

private:
    Stack<double> numbers;
    Stack<char> operations;

    void process(string expr) {
        string current;
        bool isUnary = 1;
        for (int i = 0; i < expr.length();) {
            char ch = expr[i];
            if (ch == ' ') {
                continue;
            }
            else if (std::isdigit(ch) || ch == '.' || ch == '-' && isUnary == 1) {
                current += ch;
                if (ch == '-') {
                    isUnary = 0;
                }
            }
            else {
                if (!current.empty()) {
                    numbers << std::stod(current);
                    current.clear();
                }
                if (ch == '+' || ch == '-' && isUnary == 0 || ch == '*' || ch == '/') {
                    char top;
                    if (operations.isEmpty()) {
                        operations << ch;
                    }
                    if (!operations.isEmpty()) {
                        operations >> top;
                        if (isMoreImportant(ch, top)) {
                            operations << top;
                            operations << ch;
                        }
                        else {
                            operations << top;
                            calculate(numbers, operations);
                            i-=1;
                        }
                    }
                }
               
                
                if (ch == '(') {
                    operations << ch;
                }
                if (ch == ')') {
                    char top;
                    operations >> top;
                    while (top != '(') {
                        calculate(numbers, operations);
                        operations >> top;
                    }
                }
            }
        }
        if (!current.empty()) {
            numbers << std::stod(current);
        }
        
    
        
        if (!current.empty()) {
            numbers << std::stod(current);
        }
        while (!operations.isEmpty()) {
            calculate(numbers, operations);
        }
    }

    int getPriority(char ch) {
        if (ch == '+' || ch == '-') {
            return 1;
        }
        else if (ch == '*' || ch == '/') {
            return 2;
        }
        else {
            return 0;
        }
    }

    bool isMoreImportant(char ch1, char ch2) {
        return (getPriority(ch1) > getPriority(ch2));
    }

    void calculate(Stack<double>& numbers, Stack<char>& operations) {
        double a, b, c;
        char op;
        numbers >> a;
        operations >> op;
        switch (op) {
        case '+':
            numbers >> b;
            c = a + b;
            numbers << c;
            break;
        case '-':
            numbers >> b;
            c = b - a;
            numbers << c;
            break;
        case '*':
            numbers >> b;
            c = a * b;
            numbers << c;
            break;
        case '/':
            numbers >> b;
            c = b / a;
            numbers << c;
            break;
        }
    }
};

int main() {
    string expression;
    std::getline(cin, expression);
    Calc calculator;
    try {
        cout << calculator.getResult(expression);
    }
    catch (std::out_of_range) { std::cerr << "stack out of range"; }
    return 0;
}
