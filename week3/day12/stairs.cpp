// Climbing Stairs Problem
#include <iostream>
#include <vector>
using namespace std;

int climb(int n, vector<int>& dp){
    // He can climb one or 2 steps
    if (n<=1) return n;

    // Check if we calculated it before
    if (dp[n] != -1) return dp[n];
    

    // If we don't calculate it before, then get it from the recurrence relation
    dp[n] = climb(n-1, dp) + climb(n-2, dp);
    return dp[n];
}

int main() {
    int n = 10; // stair num where I want tp reach
    vector<int> dp(n,-1);
    return 0;
}
