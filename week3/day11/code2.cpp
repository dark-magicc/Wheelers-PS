#include <iostream>
using namespace std;

int bin_search(int arr[], int l, int r, int k){
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (arr[mid] == k){
            return mid;
        }
        else if (arr[mid] < k){
            l = mid +1;
        }
        else{
            r = mid -1;
        }
    }
    
    return -1;
}

int bin_search_with_recursive(int arr[], int l, int r, int k){
    if (l > r){
        return -1;
    }
    int mid = (l + r)/2;

    if (arr[mid] == k){
        return mid;
    }
    else if(arr[mid] < k) {
        return bin_search_with_recursive(arr, mid+1, r, k);
    }
    else{
        return bin_search_with_recursive(arr, l, mid-1, k);
    }

}


int main() {
    int arr[] = {1,3,5,7,9};
    int result;
    int r = (sizeof(arr) / sizeof(arr[0]) -1);
    result = bin_search_with_recursive(arr, 0, r, 10);
    if (result  == -1){
        cout << "Not found";
    }
    else{
        cout << " found with index : " << result;
    }
    return 0;
}