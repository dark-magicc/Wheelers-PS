#include <iostream>
#include <vector>
using namespace std;

void fill_vector(vector<int> & v){
    for (int i = 0; i< v.size(); i++){
        cout<< "Enter ele with index " << i << ": ";
        cin >> v[i];
    }
}

int cal_no_of_subsets(vector<int> v,int length ,int target){
    int no_of_subsets = 0;
    for (int mask = 0; mask < (1<<length); mask++){
        int sum = 0;
        for (int bit = 0 ; bit < length ; bit++){
            if (mask & (1<<bit)){
                sum += v[bit];
            }
        }
        if (sum == target){
            no_of_subsets++;
        }
    }
    return no_of_subsets;
}

int main() {
    int n; // size of vector
    int target; // target to check if subset sum is equal to that target

    cout << "enter the size of array : ";
    cin >> n;

    cout << "enter the target : ";
    cin >> target;

    vector<int> v(n);
    fill_vector(v);

    cout << cal_no_of_subsets(v,v.size(), target);

    return 0;
}