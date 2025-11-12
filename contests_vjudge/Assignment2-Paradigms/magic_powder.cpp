// Idea: use binary search to find the maximum number of cakes we can make

#include <iostream>
#include <vector>
#define ll long long
using namespace std;


// That function takes a number and check if we can make that number of cake (return true, else return false)
bool can_make_cake(ll mid, vector<int>& needed_amount, vector<int>& available_amount, int k){
    ll required_magic_powder = 0;

    for (int i = 0; i < needed_amount.size(); i++)
    {
        ll need = 1ll* needed_amount[i]* mid;
        if (available_amount[i] < need)
        {
            required_magic_powder += need - available_amount[i];
            if (required_magic_powder > k)
            {
                return false;
            }
            
        }
        
    }
    // If required amount of magic powder is greater that the amount I have
    if (required_magic_powder > k)
    {
        return false;
    }
    else{
        return true;
    }

}

int main() {
    int num_of_ingredients, magic_powder_weight;
    cin >> num_of_ingredients >> magic_powder_weight;

    vector<int> needed_amount(num_of_ingredients);
    vector<int> available_amount(num_of_ingredients);

    for (int i = 0; i < num_of_ingredients; i++)
    {
        cin >> needed_amount[i];
        
    }
    for (int i = 0; i < num_of_ingredients; i++)
    {
        cin >> available_amount[i];
    }

    
    int cakes = 0;

    ll left = 0;
    ll right = 2e9; // Max number in int

    while (left <= right) // binary search condition (will exit if l == r only when the two pointers be at the same number)
    {
        ll mid = (right + left)/2;
        if (can_make_cake(mid, needed_amount, available_amount, magic_powder_weight))
        {
            cakes = mid; // update value of cakes we can make
            left = mid+1;
        }
        else{
            right = mid -1;
        }
    }
    
    cout << cakes;
    return 0;
}