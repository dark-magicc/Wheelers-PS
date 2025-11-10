// Subset Sum Finder
// Idea: use iterative complete search (take- leave)

#include <iostream>
#include <vector>
using namespace std;

bool check_subset_sum(int target, vector<int>&v, int i, int sum){
    if (i == v.size()){
        if (sum == target){
            return true;
        }
        else{
            return false;
        }
    }
    // Take
    bool take = check_subset_sum(target, v, i+1, sum+v[i]);
    bool leave = check_subset_sum(target, v, i+1, sum);

    return take|| leave;
}

int main() {
    int size;
    cin >> size;

    vector<int> v;
    for (int i = 0; i < size; i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int target;
    cin >> target;
    cout << check_subset_sum(target, v, 0, 0);

    return 0;
}