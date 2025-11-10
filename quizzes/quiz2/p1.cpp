// Optimized solution (O(nlog(n)))
// If you used complete search (nested loop) : O(n^2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Idea: get index of the element and 
//it indicate no of elements that is less than or 
// equal the ele I (the index where we can put in the array to keep it sorted)
int modified_binary_search(vector<int> v1, int ele, int l, int r){
    if( l > r){ // base case (when to stop)
        return l;
    }
    int mid = (l+r)/2;
    if  (v1[mid] < ele){
        return modified_binary_search(v1, ele, mid+1, r);
    }
    else{
        return modified_binary_search(v1, ele, l, mid-1);
    }
}

void fill_vector(vector<int> & v){
    for (int i = 0; i< v.size(); i++){
        cout << "Enter element of index " << i << endl;
        cin >> v[i];
    }
}

int main() {
    // Idea, we will make use of binary search concept to
    // find number of elements that is less than or equal
    // elements of second array

    // Use vector as the size is dynamic
    int n1,n2;
    cout << "Entet the size of first array" << endl;
    cin >> n1; 
    cout << "Entet the size of first array" << endl; 
    cin >> n2; 
    
    // Initalize vector
    vector<int> v1(n1);
    vector<int> v2(n2);

    // Fill vectors
    fill_vector(v1);
    fill_vector(v2);

    // sort first array if it is not sorted so I can use binary search approach
    sort (v1.begin(), v1.end());

    // loop for second array elements and print required output
    for (int i : v2){
        cout <<  modified_binary_search(v1, i, 0, v1.size()-1) << endl;
    }
    
    return 0;
}