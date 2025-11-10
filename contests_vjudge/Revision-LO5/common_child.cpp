// Longest Common Subsequence
// LCS
// Longest Common Child

// Idea: Use dynamic programming 
// Start from the simplest problem, build the dp table,  the result will be dp[s1.size][s2.size]
// Code: nested loop (and inside if condition)

// Note: that problem tests LO5(string) - LO1(paradigms- Dynamic Programming)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longest_common_subseqence(string& s1, string& s2){
    vector<vector<int>> dp(s1.size()+1, 
                           vector<int>(s2.size()+1, 0)
                        );

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    

    return dp[s1.size()][s2.size()];
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;

    cout << longest_common_subseqence(s1, s2);
    
    return 0;
}