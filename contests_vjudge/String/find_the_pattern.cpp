// Rapin Karp Algorithm to find all occurance of pattern in a text

#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

// add
ll add(ll a, ll b, ll m)
{
    return ((a % m) + (b % m) % m);
}

// sub
ll sub(ll a, ll b, ll m)
{
    return (((a % m) - (b % m) + m) % m);
}
// mul
ll mul(ll a, ll b, ll m)
{
    return ((a % m) * (b % m) % m);
}

// push
ll push(ll hash, ll base, ll ch, ll m)
{
    ll tmp = mul(hash, base, m);
    ll res = add(tmp, ch, m);
    return res;
}

// pop
ll pop(ll hash, ll base_power, ll ch, ll m)
{
    ll tmp = mul(base_power, ch, m);
    ll res = sub(hash, tmp, m);
    return res;
}

// binary expo
ll binary_expo(ll base, ll power, ll m)
{
    ll res = 1;
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            res = mul(res, base, m);
        }
        base = mul(base, base, m);
        power = power / 2;
    }
    return res;
}

int main()
{
    string txt = "hajsfkasff";
    string pat = "ab";

    // Take input from user
    cin >> txt;
    cin >> pat;

    int txt_size = txt.size();
    int pat_size = pat.size();

    // To store number of occurence of pattern in the text and its start position
    int no_of_appear = 0;
    vector<int> v;

    // Constants
    ll base = 131;
    ll mod = 1e9 + 7;
    ll base_power = binary_expo(base, pat_size - 1, mod);

    // Init hash for pattern and window
    ll hash_window = 0, hash_pat = 0;

    // Calculate hash for pattern and first window (we will use function push to calculate it)
    for (int i = 0; i < pat_size; i++)
    {
        hash_pat = push(hash_pat, base, pat[i], mod);
        hash_window = push(hash_window, base, txt[i], mod);
    }

    // Check if hash of first window == hash of pattern
    if (hash_window == hash_pat)
    {
        no_of_appear++;
        v.push_back(0);
    }

    // Calculate hash for remining windows
    for (int i = pat_size; i < txt_size; i++)
    {
        hash_window = pop(hash_window, base_power, txt[i - pat_size], mod);
        hash_window = push(hash_window, base, txt[i], mod);

        if (hash_window == hash_pat)
        {
            no_of_appear++;
            v.push_back(i - pat_size + 1);
        }
    }

    if (no_of_appear == 0)
    {
        cout << "Not found";
    }
    else
    {
        cout << no_of_appear << endl;
        for (int i : v)
        {
            cout << i + 1 << endl;
        }
    }

    return 0;
}