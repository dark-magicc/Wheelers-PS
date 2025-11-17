#include <iostream>
#include <vector>
using namespace std;
int no_of_sets = 0;

void cal_subset_sum(vector<int> v, int target, int length, int sum, int i){
    if ( i == length){  // Base condition
        if (sum == target){
            no_of_sets++;
        }
        return;
    }
    // take
    cal_subset_sum(v, target, length, sum + v[i], i+1);

    // leave
    cal_subset_sum(v, target, length, sum , i+1);

}

int main() {
    vector<int> v ={5,1,4,2,3,1,3,10,9};
    int target = 16;
    int length = v.size();
    
    cal_subset_sum(v, target, length, 0 , 0);

    cout << no_of_sets;
    return 0;
}