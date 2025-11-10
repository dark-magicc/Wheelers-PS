#include <iostream>
#include <vector>
using namespace std;

void merge(vector<vector<int>> &v, int l1, int r1, int l2, int r2){
    int n1 = (r1 - l1)+1;
    int n2 = (r2 - l2)+1;

    vector<vector<int>> tmp1(n1);
    vector<vector<int>> tmp2(n2);

    // Copy data to tmp
    for (int i=0; i <n1; i++){
        tmp1[i] = v[l1+i];
    }
    for (int i=0; i <n2; i++){
        tmp2[i] = v[l2+i];
    }
    // pivots
    int i1 = 0,
        i2 = 0,
        left = l1;

    // case 1
    while(n1 != 0 && n2 != 0){
        if (tmp1[i1][0] < tmp2[i2][0]){
            v[left] = tmp1[i1];
            i1++;
            left++;
            n1 --;
        }
        else{
            v[left] = tmp2[i2];
            i2++;
            left++;
            n2 --;
        }
    }
    // case 2
    while (n1 != 0){
        v[left] = tmp1[i1];
        i1++;
        left++;
        n1 --;
    }
    // case 3
    while (n2 != 0){
        v[left] = tmp2[i2];
        i2++;
        left++;
        n2 --;
    }
}

void merge_and_sort(vector<vector<int>> &v, int l ,int r){
    if (l ==r){
        return;
    }
    int mid = (l+r) /2;
    merge_and_sort(v,l, mid);
    merge_and_sort(v,mid+1, r);

    merge(v, l, mid, mid+1, r);
}


int main() {
    vector<vector<int>> v = {{2,6},{8,10},{15,18},{1,3}};
    int length = v.size() -1;
    merge_and_sort(v,0, length);

    for (auto i : v){
        cout << i[0] << " " << i[1] << endl; 
    }

    vector<vector<int>> merged;
    merged.push_back(v[0]);

    for (int i=1; i< v.size(); i++){
        if (v[i][0] < merged.back()[1]){  // overlap
            merged.back()[1] = max(merged.back()[1], v[i][1]);
        }
        else{
            merged.push_back(v[i]);
        }
    }

    for (auto i : merged){
        cout << i[0] << " " << i[1] << endl; 
    }

    return 0;
}