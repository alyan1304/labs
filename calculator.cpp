#include "myStack.h"
#include <string>
#include <cctype>
using std::string;
using std::cin;
using std::cout;

//не доделала до конца, но уже 4 утра, поэтому сдаю как есть ))(

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

    void process(std::string expr) {
        string current;
        for (char ch : expr) {
            if (ch == ' ') {
                continue;
            }
            else if (std::isdigit(ch) || ch == '.') {
                current += ch;
            }
            else {
                if (!current.empty()) {
                    numbers << std::stod(current);
                    current.clear();
                }
                if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                    while (!operations.isEmpty()) {
                        char top;
                        operations >> top;
                        if (isMoreImportant(ch, top)) {
                            operations << top;
                            break;
                        }
                        else {
                            calculate(numbers, operations);
                        }
                    }
                    operations << ch;
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
        return getPriority(ch1) > getPriority(ch2);
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
    cout << calculator.getResult(expression);
    return 0;
}
