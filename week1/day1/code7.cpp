// try throw catch in details

#include <iostream>
#include <string>
using namespace std;

// Function to divide two numbers
double divide(double numerator, double denominator) {
    // Check for division by zero
    if (denominator == 0) {
        // Throw an exception with a message
        throw runtime_error("Error: Division by zero is not allowed.");
    }

    // If no error, return the result
    return numerator / denominator;
}

int main() {
    cout << "=== Exception Handling Example ===" << endl;

    double num, den;
    cout << "Enter numerator: ";
    cin >> num;

    cout << "Enter denominator: ";
    cin >> den;

    try {
        // The try block contains code that might throw an exception
        double result = divide(num, den);

        // If no exception occurs, this line executes
        cout << "Result = " << result << endl;
    }

    // Catch block handles the exception thrown by the try block
    catch (const runtime_error &e) {
        // Print the error message
        cout << "Caught an exception: " << e.what() << endl;
    }

    // You can have multiple catch blocks for different exception types
    catch (const exception &e) {
        // This block catches any other standard exceptions
        cout << "General exception caught: " << e.what() << endl;
    }

    cout << "Program continues normally after handling exception." << endl;

    return 0;
}
