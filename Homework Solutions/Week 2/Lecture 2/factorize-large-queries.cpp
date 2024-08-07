// Author: Berke Dönmez
// Editorial: Anıl Dervişoğlu
// Question Link: https://algoleague.com/contest/nice-to-math-you/problem/factorize-large-queries/detail 

/*
 * Similar to 'Factorize Queries' question, we are required to find the number
 * of divisors each given query has but this time the queries are numbers
 * up to '10^10', which we cannot create a sieve table for.
 *
 * So, for this question we need an important observation.
 * This is that the primes up to 'sqrt(n)' are the only primes
 * that can be the factors of number 'n'.  Within our constraints,
 * 'n' being '10^10' and 'sqrt(n)' being '10^5', we can
 * calculate the primes up to 'sqrt(n)' and find the factors of
 * each query using these precalculated prime numbers.
 *
 * The time complexity here would be: To calculate primes up to 'sqrt(n)'
 * the complexity would be 'O(sqrt(n)*log(sqrt(n))' and answering each query
 * would have the complexity of 'O(q*log(sqrt(n)))' where 'log(n)' would
 * give the approximate number of primes up to n. Hence, we would have a
 * total complexity of: 'O((q+sqrt(n))*log(sqrt(n)))' which is within our limits.
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int A = 1e5 + 5;

int main() {
    // vector to calculate and store primes up to sqrt(n)
    vector<bool> is_prime(A, 1);
    vector<int> primes;
    for (int i = 2; i < A; i++) {
        if (!is_prime[i])
            continue;
        primes.push_back(i);
        for (int k = 2 * i; k < A; k += i)
            is_prime[k] = 0;
    }

    int q;
    cin >> q;
    // Getting each query
    while (q--) {
        ll x; // because of constraints it should be long long
        cin >> x;
        int n_divisors = 1;
	// Checking the primes vector to find which ones are the factors of the given query
        for (int p : primes) {
            if (1ll * p * p > x)
                break;
            int exp = 0;
            while (x % p == 0) {
                x /= p;
                exp++;
            }
	    // Calculating divisor count mathematically
            n_divisors *= exp + 1;
        }
        if (x > 1)
            n_divisors *= 2;
        cout << n_divisors << "\n";
    }
}
