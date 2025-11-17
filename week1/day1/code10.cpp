// Write a C++ program to find the factorial of an input number

#include <iostream>
using namespace std;

int main() {
    int n;
    long long factorial = 1; // use long long to handle large results

    cout << "Enter a non-negative integer: ";
    cin >> n;

    // Factorial is not defined for negative numbers
    if (n < 0) {
        cout << "Error: Factorial of a negative number doesn't exist." << endl;
        return 0; // stop the program
    }

    // 0! = 1 (by definition)
    // Loop from 1 to n to calculate factorial
    for (int i = 1; i <= n; ++i) {
        factorial *= i; // multiply factorial by each i
    }

    cout << "Factorial of " << n << " = " << factorial << endl;

    return 0;
}
