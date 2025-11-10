#include <iostream>
#include <string>

#define ll long long
using namespace std;


// tools 
// (a+b)%m
ll add(ll a, ll b, ll m){
    ll res = ((a%m)+(b%m))%m;  // to avoid overflow
    return res;
}


// (a-b)%m
ll sub(ll a, ll b, ll m){
    ll res = ((a%m)-(b%m) +m)%m;  // we add m to avoid negative number
    return res;
}


// (a*b)%m
ll mul(ll a, ll b, ll m){
    ll res = ((a%m) * (b%m))%m;
    return res;
}

// push (add new char to generate new hash)
ll push(ll ch, ll m, ll base, ll h){
    //  tmp = h * base 
    //  h = tmp + ch 
    ll tmp = mul(h, base, m);
    ll res = add(ch, tmp, m);
    return res;
}


// pop (remove the first char from the hash)
ll pop(ll ch, ll m, ll h, ll base_power){
    // h(new) = h(old) - ch * base_power
    ll tmp = mul(ch, base_power, m);
    ll res = sub(h, tmp, m);
    return res;
}


// make fun power with complexity O(log(n))
ll binary_expo(ll base, ll power, ll m){
    ll res = 1;
    while (power> 0)
    {
        if (power %2 == 1) // odd power > multiply result with base
        {
            res = mul(res, base, m);
        }
        base = mul (base, base, m);
        power = power /2;
    }
    return res;
}




int main() {
    string txt = "acbcdadabcaabca";
    string pat = "abc";

    int txt_size = txt.size();
    int pat_size = pat.size();   //n

    ll mod = 1e9+7;        // big prime number
    ll base = 131;          // as we want to represent 127 char, so choose the next prime number as a base

    ll base_power = binary_expo(base, pat_size-1, mod);   // calculate the constant as we will need it in pop (base power (n-1))

    ll hash_pat = 0, hash_window = 0;          // init first hashs
    for (int i = 0; i < pat_size; i++)
    {
        // calculate hash of pattern
        hash_pat = push(pat[i], mod, base, hash_pat);

        // calculate hash of first window
        hash_window = push(txt[i], mod, base, hash_window);
    }

    // compare the hash of pattern with the hash of first window , if equal: the pattern appears at index 0
    if (hash_pat == hash_window){
        cout << 0 << endl;
    }

    // Calculate hash for remining windows by pop the first char and push the new char 

    for (int i = pat_size; i < txt_size; i++)
    {
        // pop
        hash_window = pop(txt[i - pat_size], mod, hash_window, base_power);
        
        // push
        hash_window = push(txt[i], mod, base, hash_window);

        // Compare the hash of pattern with the hash of current window, if equal: means that pattern appear at that window
        if (hash_window == hash_pat){
            cout << (i - pat_size +1) << endl;  // print the start index of the pattern
        }
    }
    
    return 0;
}