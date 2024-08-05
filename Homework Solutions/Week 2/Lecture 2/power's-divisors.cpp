// Author: Ali Emre Kaya

// Time Complexity: O(√n*log(n))
// Space Complexity: O(1)
// Question: https://algoleague.com/contest/nice-to-math-you/problem/powers-divisors

/*
Approach:

To determine the number of divisors of the form n^n for a given number n, we can use its prime factorization.

Steps:
1. Prime Factorization: Decompose n into its prime factors and determine the exponent for each prime factor.
2. Count Divisors of the Form n^n: 
    The number of such divisors is derived from considering all combinations of prime factors with their exponents multiplied by n. 
    The count is given by (n * exp + 1) for each prime factor, where exp is the exponent of the prime factor in the factorization of n.
3. Combine Results: Multiply the contributions from each prime factor to get the total number of divisors of the form n^n.

--Example for n = 60:

1. Prime Factorization:
   - 60 = 2^2 * 3^1 * 5^1

2. 60^60 == (2^2 * 3^1 * 5^1)^60 == 2^(60*2) * 3^(60*1) * 5^(60*1):
   - For prime factor 2: (60*2 + 1) = 121
   - For prime factor 3: (60*1 + 1) = 61
   - For prime factor 5: (60*1 + 1) = 61

3. Total Number of Divisors of the Form x^2:
   - Multiply the contributions: 121 * 61 * 61 = 450.241
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    ll ans = 1;
    ll power = n;
    // time complexity of for loop: O(√n)
    for (int i = 2; 1ll * i * i <= n; i++) {
        int exp = 0;
        // time complexity of while loop: O(log(n))
        while (n % i == 0) {
            n /= i;
            exp++;
        }
        ans *= (power * exp) % mod + 1;
    }
    // If n is still greater than 1, it means n is prime, and has an exponent of 1
    if (n > 1){
        ans *= (power * 1) % mod + 1;
    }
    cout << ans << "\n";
}