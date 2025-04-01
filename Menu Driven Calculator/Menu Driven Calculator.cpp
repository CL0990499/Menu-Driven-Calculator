#include <iostream>
#include <limits> // for numeric_limits

// Arithmetic functions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Division by zero is not allowed." << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
    }
    return a / b;
}

double modulo(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Modulo by zero is not allowed." << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
    }
    return static_cast<int>(a) % static_cast<int>(b); // modulo only works with integers
}

int main() {
    int choice;
    double num1, num2;

    while (true) {
        // Display the menu
        std::cout << "===== Calculator Menu =====" << std::endl;
        std::cout << "1. Addition" << std::endl;
        std::cout << "2. Subtraction" << std::endl;
        std::cout << "3. Multiplication" << std::endl;
        std::cout << "4. Division" << std::endl;
        std::cout << "5. Modulo" << std::endl;
        std::cout << "6. Exit" << std::endl;

        // Get user's choice
        std::cout << "Choose an option: ";
        std::cin >> choice;

        // Check for invalid input
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore invalid input
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }

        // Handle the exit option
        if (choice == 6) {
            std::cout << "Exiting program..." << std::endl;
            break;
        }

        // Check if the choice is valid
        if (choice < 1 || choice > 6) {
            std::cout << "Invalid option. Please select a valid option from the menu." << std::endl;
            continue;
        }

        // Prompt for the numbers
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        // Perform the operation based on user's choice
        switch (choice) {
        case 1: {
            double result = add(num1, num2);
            std::cout << "Result: " << result << std::endl;
            break;
        }
        case 2: {
            double result = subtract(num1, num2);
            std::cout << "Result: " << result << std::endl;
            break;
        }
        case 3: {
            double result = multiply(num1, num2);
            std::cout << "Result: " << result << std::endl;
            break;
        }
        case 4: {
            double result = divide(num1, num2);
            if (!std::isnan(result)) {
                std::cout << "Result: " << result << std::endl;
            }
            break;
        }
        case 5: {
            double result = modulo(num1, num2);
            if (!std::isnan(result)) {
                std::cout << "Result: " << result << std::endl;
            }
            break;
        }
        default:
            std::cout << "Invalid option." << std::endl;
            break;
        }
    }

    return 0;
}
