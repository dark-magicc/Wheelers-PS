// Find All Divisors (Simple Version)*

#include <iostream>
#include <vector>
using namespace std;

vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0)
            divisors.push_back(i);
    }
    return divisors;
}

int main() {
    int n;
    cin >> n;
    vector<int> divisors = findDivisors(n);
    for (int d: divisors)
        cout << d << " ";
    cout << "\n";
}