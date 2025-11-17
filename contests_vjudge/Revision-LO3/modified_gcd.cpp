#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    int n = gcd(a, b);
    // Get all divisors of n
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (n / i != i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int max_common_divisor = -1;
        int low, high;
        cin >> low >> high;
        for (int d : divisors)
        {
            if (d >= low && d <= high)
            {
                max_common_divisor = max(max_common_divisor, d);
            }
        }
        cout << max_common_divisor << endl;
    }

    return 0;
}