// Author: Murat Biberoglu
// Question Link: https://algoleague.com/problem/large-binomial-coefficient

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAX_N = 1000000;  // Maximum value for precomputation
const ll MOD = 998244353;  // Modulo value

// Function to compute the modular inverse using Fermat's Little Theorem
ll mod_inverse(ll number) {
    ll pwr = MOD - 2;  // Exponent for modular inverse calculation
    ll ans = 1;
    while (pwr) {
        if (pwr % 2)
            ans = (ans * number) % MOD;    // If power is odd, multiply the result
        number = (number * number) % MOD;  // Square the number
        pwr >>= 1;                         // Divide the power by 2
    }
    return ans;  // Return the modular inverse
}

void solve() {
    ll n, k;
    cin >> n >> k;  // Read n and k
    if (k == 0 || n == k) {
        cout << "1\n";  // If k is 0 or k equals to n, the result is 1
        return;
    }

    k = min(k, n - k);
    n = n % MOD;
    ll numerator = 1, denominator = 1;
    for (ll i = 1; i <= k; i++) {
        numerator = (numerator * (n + 1 - i)) % MOD;
        denominator = (denominator * i) % MOD;
    }
    cout << (numerator * mod_inverse(denominator)) % MOD << "\n";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
