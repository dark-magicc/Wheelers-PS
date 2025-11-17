// Check Prime (basic version)
#include <iostream>
using namespace std;

bool isPrime(int n) {
    // if n is less than 2 (0 or 1), it's not a prime
    if (n < 2)
        return false;
    // check if n has any divisors from 2 to n - 1
    for (int i = 2; i < n; ++i) {
        // if any divisor is found, n is not a prime
        if (n % i == 0)
            return false;
    }
    // if no divisor is found, n is a prime
    return true;
}

int main() {
    int n;
    cin >> n;
    if (isPrime(n)) {
        cout << "Prime\n";
    }
    else {
        cout << "Not a Prime\n";
    }
}