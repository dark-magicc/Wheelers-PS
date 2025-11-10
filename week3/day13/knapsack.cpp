#include <iostream>
#include <vector>
using namespace std;

int cal_max_knapsack_value(vector <int> weights, 
                            vector <int> values ,
                            vector<vector <int> >& dp ,
                            int max_knapsack_weight )
{
    // nested loop:
    for (int i = 1; i <= weights.size(); i++){
        for (int j = 0; j <= max_knapsack_weight; j++){
            if (weights[i-1] <= j){
                dp[i][j] = max(
                    dp[i-1][j],
                    (values[i-1] + dp[i-1][j - weights[i-1]])
                );
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }

    }

    return dp[weights.size()][max_knapsack_weight];

}

int main() {
    vector <int> weights = {1,2,3,4};
    vector <int> values = {30,70,100,80};
    int max_knapsack_weight = 7;
    vector<vector <int> > dp (weights.size()+1, 
             vector<int> (max_knapsack_weight+1,  0));

    int res = cal_max_knapsack_value(weights, values, dp, 
                                    max_knapsack_weight);

    cout << res;
    
    return 0;
}