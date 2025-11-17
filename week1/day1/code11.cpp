// Write a C++ program to print the count of prime numbers within a range.

#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // Numbers less than or equal to 1 are not prime
    if (n <= 1)
        return false;

    // Check divisibility from 2 to sqrt(n)
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) // if divisible, not prime
            return false;
    }

    return true; // no divisors found → prime
}

int main() {
    int start, end;

    cout << "Enter the starting number of the range: ";
    cin >> start;
    cout << "Enter the ending number of the range: ";
    cin >> end;

    // Validation: ensure start <= end
    if (start > end) {
        cout << "Invalid range! Starting number must be less than or equal to ending number." << endl;
        return 0;
    }

    int primeCount = 0; // counter for prime numbers

    // Loop through the range and check each number
    for (int num = start; num <= end; ++num) {
        if (isPrime(num)) // call helper function
            primeCount++;
    }

    cout << "There are " << primeCount
         << " prime numbers between " << start
         << " and " << end << "." << endl;

    return 0;
}
