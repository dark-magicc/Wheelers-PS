#include <iostream>
#include <string>
#include <vector>
#define ll long long

using namespace std;
// add
ll add(ll a, ll b, ll m){
    ll res = ((a%m)+(b%m))%m;
    return res;
}

// sub
ll sub(ll a, ll b, ll m){
    ll res = ((a%m)-(b%m) +m)%m;
    return res;
}

// mul
ll mul(ll a, ll b, ll m){
    ll res = ((a%m)*(b%m))%m;
    return res;
}

// push
ll push(ll ch, ll m, ll base, ll hash){
    ll tmp = mul(hash, base, m);
    ll res = add(tmp, ch, m);
    return res;
}

// pop
ll pop(ll ch, ll m, ll base_power, ll hash){
    ll tmp = mul(ch, base_power, m);
    ll res = sub(hash, tmp, m);
    return res;
}

// binary exponentiation
ll binary_expo(ll base, ll power, ll m){
    ll res =1 ;
    while (power > 0){
        if (power %2  == 1)
        {
            res = mul(res, base, m);
        }
        base = mul (base, base, m);
        power = power /2;
    }
    
    return res;
}

int main() {
    int t;
    cin >> t;
    int index = 1;

    while (t-- >0)
    {
        int count = 0;
        string txt;
        string pat;
        cin >> txt >> pat;

        int txt_size = txt.size();
        int pat_size = pat.size();

        ll m = 1e9 +7;
        ll base = 131;
        ll base_power = binary_expo(base, pat_size-1, m);
        
        ll hash_pat = 0;
        ll hash_window = 0;

        for (int i = 0; i < pat_size; i++)
        {
            hash_pat = push(pat[i], m, base, hash_pat);
            hash_window = push(txt[i], m, base, hash_window);
        }
        if (hash_pat == hash_window)
        {
            count++;
        }
        
        // remaining window
        for (int i = pat_size; i < txt_size; i++)
        {
            hash_window = pop(txt[i-pat_size], m, base_power, hash_window);
            hash_window = push(txt[i], m, base, hash_window);

            if (hash_window == hash_pat)
            {
                count ++;
            }
            

        }
        

        cout << "Case " << index <<": " << count << endl;


        index++;
    }
    
    return 0;
}