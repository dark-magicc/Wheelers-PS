// Given a range from [1:n]
// find two numbers in that range that achieve max gcd

/*
To get the maximum GCD of any two numbers from 1 to n:

The largest GCD happens when one number is a multiple of the other — for example, (2, 4) → gcd = 2.

The biggest number that can still have a multiple ≤ n is ⌊n / 2⌋.
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t-- >0)
    {
        int n;
        cin >> n;
        int a = n/2;
        cout << a << endl;
    }

    return 0;
}