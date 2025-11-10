// Find All Divisors (Optimized Version)

#include <iostream>
#include <vector>
using namespace std;


vector<int> findDivisor(int n) {
    vector<int> divisors;
    // iterate through numbers up to sqrt of n
    for (int i = 1; i * i <= n; ++i) {
        // if i is a divisor
        if (n % i == 0) {
            // add it to the divisors vector
            divisors.push_back(i);
            // if i is not the same as n / i, add n / i to the divisors vector too
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    return divisors;
}

int main() {
    int n;
    cin >> n;
    vector<int> divisors = findDivisor(n);
    for (int d : divisors)
        cout << d << " ";
    cout << "\n";
}