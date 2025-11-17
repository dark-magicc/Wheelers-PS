// Write a C++ program to check if the input number is prime or not


#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // 0, 1 and negative numbers are not prime
    if (n <= 1) {
        cout << n << " is NOT a prime number." << endl;
        return 0;
    }

    bool isPrime = true; // assume it's prime until proven otherwise

    // check divisibility up to sqrt(n)
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) { // if divisible, not prime
            isPrime = false;
            break;
        }
    }

    if (isPrime)
        cout << n << " is a PRIME number." << endl;
    else
        cout << n << " is NOT a prime number." << endl;

    return 0;
}
