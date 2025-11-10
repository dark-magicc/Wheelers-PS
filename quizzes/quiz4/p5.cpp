// Longest Increasing Subsequence

#include <iostream>
#include <vector>
using namespace std;

int lis(vector<int> &v, int size)
{
    vector<int> dp(size, 1);  // To store LIS for all seqence that ends in index i

    int res = 1; // To store max LIS until now
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(dp[i], res);
    }
    return res;
}

int main()
{
    int size;
    cin >> size;

    vector<int> v(size);

    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    cout << lis(v, size);

    return 0;
}