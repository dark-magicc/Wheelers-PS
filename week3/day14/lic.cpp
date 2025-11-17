// Make use of tabulation (dynamic programming) to get the longest increasing subsequence of a vector


#include <iostream>
#include <vector>
using namespace std;

int longest_increasing_subsequence(vector<int>& v, vector<int>& dp){
    int ans =1;
    for (int i = 1; i < v.size(); i++){
        for (int j = 0;j < i; j++){
            if (v[i]>v[j]){
                dp[i] = max (dp[i], 1+ dp[j]);
            }
        }
        ans  = max (dp[i], ans);  // We want to get the max value stored in DP
                                  // As the longest subsequence may end at any dp[i]
    }
    return ans;
}

int main(){
    vector <int> v = {3,4,5,2,8};
    vector <int > dp (v.size(), 1); // init vector dp with the same size of vector and inital value of 1
                                    // dp[i] represents the max subseqence that ends in element i
    int res = longest_increasing_subsequence(v,dp);
    cout << res;

    return 0;
}