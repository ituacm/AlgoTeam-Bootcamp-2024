// Author: Berke Dönmez
// Editorial: Anıl Dervişoğlu
// Question Link: 

/*
 * The question asks to factorize and print each given
 * queries of numbers into its primes in a sorted manner.
 * In this question, as we have many queries, the time complexity
 * would be too much to handle factorizing each query simply by
 * looking through the numbers up to 'sqrt(n)'. Hence, we have
 * to find a faster way which would factorize the queries faster.
 *
 * One of this ways is to precalculate each number's smallest prime divisor
 * and storing it in a vector, then for each each query we would look at the
 * smallest prime divisor from that vector and divide to it
 * continuously until we reach '1'. This way we would make at most 'log(n)'
 * divisions to reach '1' and calculating the vector beforehand would have
 * the complexity of 'nlog(n)' (advanced version of sieve basically).
 * Thus, having a total time complexity of 'O(n*log(n) + q*log(n))' or
 * 'O((n + q) * log(n))' which is acceptable for the contraints of this question.
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int A = 5e6 + 5;

int main() {
    // The vector to store smallest prime divisor of a number.
    vector<int> spf(A);
    for (int i = 2; i < A; i++) {
        if (spf[i])
            continue;
        for (int k = i; k < A; k += i)
	    // Looking at all the multiples of prime numbers and marking them accordingly
            if (!spf[k])
                spf[k] = i;
    }

    int q;
    cin >> q;
    // Getting all the queries and factorizing them in O(log(n)) time.
    while (q--) {
        int x;
        cin >> x;
        int n_divisors = 1;
	// prime vector to store and print the factorized elements
        vector<int> primes;
        while (x > 1) {
            int p = spf[x];
            int exp = 0;
            while (x % p == 0) {
                x /= p;
                exp++;
                primes.push_back(p);
            }
            n_divisors *= exp + 1;
        }
        cout << n_divisors << "\n";
        for (int p : primes)
            cout << p << " ";
        cout << "\n";
    }
}
