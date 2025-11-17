// Count equal pairs
// Idea: use nested loop

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> v;

    for (int i = 0; i < size; i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int no_of_equal_pairs = 0;
    for (int i= 0 ; i < (size-1); i++){
        for(int j = i+1; j< size; j++){
            if (v[i] == v[j]) no_of_equal_pairs++;
        }
    }
    cout <<no_of_equal_pairs;    
    return 0;
}