#include "basic_calc.h"

double basic_calc::BasicCalc::sqrt(double x) {
    if (x < 0) {
        std::cout << "Error: Cannot compute square root of a negative number." << std::endl;
        return -1;
    }
    return std::sqrt(x);
}

long long basic_calc::BasicCalc::factorial(long long x) {
    if (x < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers." << std::endl;
        return -1;
    }

    long long n = 1;
    for(long long i = 2; i <= x; i++) n *= i;
    return n;
}

double basic_calc::BasicCalc::natural_log(double x) {
    if (x <= 0) {
        std::cout << "Error: Logarithm is not defined for non-positive numbers." << std::endl;
        return -1;
    }
    return std::log(x);
}

double basic_calc::BasicCalc::pow(double x, double y) {
    return std::pow(x, y);
}

void basic_calc::BasicCalc::menu() {
    int choice;
    double x, y, res;
    long long n;

    std::cout << "-----------------MENU----------------" << std::endl;
    std::cout << "1. Square Root" << std::endl;
    std::cout << "2. Factorial" << std::endl;
    std::cout << "3. Natural Log" << std::endl;
    std::cout << "4. Power" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter Choice: ";
    
    std::cin >> choice;
    
    switch (choice) {
    case 1:
        std::cout << "Enter value of x: ";
        std::cin >> x;
        res = sqrt(x);
        if (res != -1) {
            std::cout << "Result: " << res << std::endl;
        }
        break;
    
    case 2:
        std::cout << "Enter value of n: ";
        std::cin >> n;
        res = factorial(n);
        if (res != -1) {
            std::cout << "Result: " << res << std::endl;
        }
        break;

    case 3:
        std::cout << "Enter value of x: ";
        std::cin >> x;
        res = natural_log(x);
        if (res != -1) {
            std::cout << "Result: " << res << std::endl;
        }
        break;

    case 4:
        std::cout << "Enter value of x: ";
        std::cin >> x;
        std::cout << "Enter value of y: ";
        std::cin >> y;
        res = pow(x, y);
        std::cout << "Result: " << res << std::endl;
        break;
    case 5:
        exit(0);
    default:
        std::cout << "Invalid choice, please try again." << std::endl;
        break;
    }
}

void basic_calc::BasicCalc::run() {
    while (true) {
        menu();
    }
}
