// Minimum Waiting Time
// Idea: Use greedy algorithm (sort the array ascending then calculate min waiting time)
// min waiting time  = sum of exection time of all tasks executed before

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int size;
    cin >> size;
    for (int i = 0; i< size; i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 1; i < size ; i++){
        for (int j = 0 ; j < i; j++){
            sum += v[j];
        }
    }
    cout << sum;
    return 0;
}