#include <iostream>
using namespace std;

int modified_binary_search(int arr[], int l, int r, int k){
    if (l > r ){ // Not found
        return -1;
    }
    int mid = (l+r) /2;
    if (arr[mid] == k){
        return mid;
    }

    // Check if first subarray is sorted
    if (arr[mid] >= arr[l]){  // indicate first sub array is sorted
        cout << "First half is sorted" << endl;
        if (k >= arr[l] && k < arr[mid]){  // indicate that element in that sorted half
           return modified_binary_search(arr, l, mid-1, k); 
        }
        else{ // drop sorted half and search in the other half
           return modified_binary_search(arr, mid+1, r, k); 
        }
    }



    else{ //indicate second sub array is sorted
        if (arr[mid+1] >= k && arr[r] <= k){ // indicate that element in that sorted half
           return modified_binary_search(arr, mid+1, r, k); 
        }
        else{ // drop sorted half and search in the other half
           return modified_binary_search(arr, l, mid-1, k); 
        }


    }
}

int main() {
    int arr[] ={4,6,8,10,1,2};
    int length = (sizeof(arr) / sizeof(arr[0])) -1;
    int result = modified_binary_search(arr, 0, length, 6);

    if (result == -1){
        cout << "Not found";

    }
    else{
        cout <<"found with index : " << result;
    }

    return 0;
}