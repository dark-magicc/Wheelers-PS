#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int check_measurements(vector<int>& v){ // Idea: to get thw longest window where v[r] <= v[l](hint: use two pointer, l start with 0 and increase if the condition didn't occur,  r start from 0 to n-1)
    int ans = 0;
    int l = 0;
    for (int r = 0; r < v.size(); r++)
    {
        while (v[r] > 2* v[l])
        {
            l++;
        }
        ans= max(ans, r-l+1);
    }
    return v.size() - ans;
}


int main() {
    // As codeforces wants to enter the input as input.txt, and output to output.txt
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    if(!(cin >>n) || n < 0) return 0;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cout << check_measurements(v);
    return 0;
}