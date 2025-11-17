// coin change problem

#include <iostream>
#include <vector>
#include <climits>  // To use INT_MAX
using namespace std;

int coin_maker(vector<int> coins, int coin_to_make,vector<int>& dp){
    // Base cases
    if (coin_to_make == 0) return 0;
    if (coin_to_make < 0) return INT_MAX;
    if (dp[coin_to_make] != -1) return dp[coin_to_make];

    int ans = INT_MAX;  // Assume that coin can not be made

    // Get min number of coins that we can use to make "coin_to_make"
    for (int coin : coins){
        int res = coin_maker(coins, coin_to_make - coin, dp);
        if ( res != INT_MAX){  // Check if we can  (coin_to_make - coin)
            ans = min (res+1, ans);  // Check if we can make it with minimal number of coins 
        }
    }
    dp[coin_to_make] = ans;  // return the value

    return ans;


}

int main() {
    int coin_to_make = 55;  
    vector<int> coins = {1,2,5};  // Available coins we can use
    vector<int> dp(coin_to_make+1, -1);
    
    int res = coin_maker(coins, coin_to_make, dp);

    if (res == INT_MAX){  // Indicate that we can't make that coin with available coins
        cout << "Impossible to make" ;
    }
    else{
        cout << "min number of coin to make " << coin_to_make << " is : " << res;
    }

    return 0;
}