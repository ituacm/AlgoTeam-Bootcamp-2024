// Author: Ali Emre Kaya

// Time Complexity: O(√n*log(n))
// Space Complexity: O(1)
// Question: https://algoleague.com/contest/nice-to-math-you/problem/squares-divisors

/*
Approach:

To determine the number of divisors of the form n^2 for a given number n, we can use its prime factorization.

Steps:
1. Prime Factorization: Decompose n into its prime factors and determine the exponent for each prime factor.
2. Count Divisors of the Form x^2: For a divisor to be a perfect square, all prime factors in its composition must have even exponents. 
    The number of such divisors is derived from considering all combinations of prime factors with even exponents. 
    The count is given by (2 * exp + 1) for each prime factor, where exp is the exponent of the prime factor in the factorization of n.
3. Combine Results: Multiply the contributions from each prime factor to get the total number of divisors of the form x^2.

--Example for n = 60:

1. Prime Factorization:
   - 60 = 2^2 * 3^1 * 5^1

2. 60^2 == (2^2 * 3^1 * 5^1)^2 == 2^(2*2) * 3^(2*1) * 5^(2*1):
   - For prime factor 2: (2*2 + 1) = 5
   - For prime factor 3: (2*1 + 1) = 3
   - For prime factor 5: (2*1 + 1) = 3

3. Total Number of Divisors of the Form x^2:
   - Multiply the contributions: 5 * 3 * 3 = 45
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll ans = 1;
    // time complexity of for loop: O(√n)
    for (int i = 2; 1ll * i * i <= n; i++) {
        // time complexity of while loop: O(log(n))
        int exp = 0;
        while (n % i == 0) {
            n /= i;
            exp++;
        }
        ans *= (2 * exp) + 1;
    }
    // If n is still greater than 1, it means n is prime, and has an exponent of 1
    if (n > 1){
        ans *= (2 * 1) + 1;
    }
    cout << ans << "\n";
}