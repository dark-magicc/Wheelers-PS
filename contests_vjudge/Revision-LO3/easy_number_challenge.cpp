
// The optimized code: (will calculate divisor count at first)
// Idea: How to calculate divisor counts
/*
1- Goal:
We want divisor_counts[n] to store the number of positive divisors of n.
For example:
divisor_counts[6] = 4 because 6 has divisors {1, 2, 3, 6}.

2- Outer loop: for (int i = 1; i <= MAX; i++)
i represents a potential divisor.
We check all numbers from 1 to MAX to see which numbers they divide.

3- Inner loop: for (int j = i; j <= MAX; j += i)
j represents numbers that i divides.
j starts at i and increments by i each time, so it hits all multiples of i.
Every time we hit a multiple of i, we increase its divisor count because i divides j.
*/
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    ll MAX = a * b * c;
    vector<int> divisor_counts(MAX + 1, 0);

    for (int i = 1; i <= MAX; i++)
    {
        for (int j = i; j <= MAX; j += i)
        {
            divisor_counts[j]++;
        }
    }

    ll ans = 0;
    ll mod = 1073741824; // 2^30
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                ll prod = i * j * k;
                ans += divisor_counts[prod];
                if (ans > mod)
                {
                    ans = ans % mod;
                }
            }
        }
    }
    cout << ans % mod;

    return 0;
}