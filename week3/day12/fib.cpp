#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &dp){
    // Base Cases
    if (n <= 1) return n;

    // If we calculate it before for that number
    if (dp[n] != -1) return dp[n];

    // If we don't calculate it, then calculate it using that relation
    return fib(n-1,dp) + fib(n-2,dp);
}

int main() {
    int n;
    cout << "Enter the term you want"<< endl;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << fib(n, dp);

    
    return 0;
}