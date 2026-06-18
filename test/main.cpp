#include <iostream>

int main() {
    char op;
    int num1, num2, result;
    int data;

    while (data != 2) {
        std::cout << "1 = calculator \n 2 = exit \n";
        std::cin >> data;

        if (data == 1) {
            std::cout << "Enter num1, num2\n";
            std::cin >> num1 >> num2;
            std::cout << "action with numbers (+, -, *, /)\n";
            std::cin >> op;

            if (op == '+') result = num1 + num2;
            else if (op == '-') result = num1 - num2;
            else if (op == '*') result = num1 * num2;
            else if (op == '/') {
                if (num2 == 0) {
                    std::cout << "На ноль делить нельзя\n";
                    continue;
                }
                result = num1 / num2;
            }
            else {
                std::cout << "Неверный оператор\n";
                continue;
            }
            std::cout << "Result: " << result << std::endl;
        } else {
            break;
        }
    }
    return 0;
}1