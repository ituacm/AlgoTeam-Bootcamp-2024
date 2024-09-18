// Author: Murat Biberoglu
// Question Link: https://algoleague.com/problem/binomial-coefficient-queries

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAX_N = 1000000;         // Maximum value for precomputation
const ll MOD = 1000000007;        // Modulo value
vector<ll> factorial(MAX_N + 1);  // Vector to store factorials modulo MOD

// Function to precompute factorials modulo MOD
void precalculate() {
    factorial[0] = 1;  // Factorial of 0 is 1
    for (int i = 1; i <= MAX_N; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;  // Compute factorial modulo MOD
}

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

// Function to solve each test case
void solve() {
    ll n, k;
    cin >> n >> k;  // Read n and k
    if (k == 0 || n == k) {
        cout << "1\n";  // If k is 0 or k equals to n, the result is 1
        return;
    }

    // Calculate the denominator for the binomial coefficient in modulo MOD
    ll denominator = mod_inverse((factorial[n - k] * factorial[k]) % MOD);
    // Output the binomial coefficient in modulo MOD
    cout << (factorial[n] * denominator) % MOD << "\n";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    precalculate();
    ll q;
    cin >> q;  // Read number of test cases
    while (q--)
        solve();  // Solve each test case
    return 0;
}
