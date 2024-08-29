// Author: Fatih Baskın
// Question Link: https://algoleague.com/contest/nice-to-math-you/problem/phi/detail

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> prime_factors(int n)
{
    // Use sieve of eratosthenes to find prime factors of n
    // Time complexity: O(sqrt(n))

    vector<int> factors;
    for (int i = 2; i * i <= n; i++)
    {
        // For loop will compare to initial n value
        // So we need to check this condition again
        if (i > n)
            break;

        if (n % i != 0)
            continue;

        // If continue is not executed, n is divisible by i
        // So, we will divide n by i until n is not divisible by i
        factors.push_back(i);

        while (n % i == 0)
            n /= i;
    }
    // At the end of the loop, n will be either 1 or a prime number
    if (n > 1)
        factors.push_back(n);
    return factors;
}

// For simplicity, int is defined as long long (64 bit signed integer) and main function is defined as int32_t (32 bit signed integer)
int32_t main()
{
    int n;
    cin >> n;

    // Find prime factors of n
    vector<int> factors = prime_factors(n);

    // Calculate phi(n) using formula
    // Euler's totient function: phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
    // where p1, p2, ..., pk are prime factors of n
    // https://en.wikipedia.org/wiki/Euler%27s_totient_function

    // If you open this expression, you will see that it is equal to n * (p1 - 1) * (p2 - 1) * ... * (pk - 1) / (p1 * p2 * ... * pk)
    // So, we can calculate phi(n) using this formula
    int phi = n;
    for (int p : factors)
    {
        phi /= p;
        phi *= p - 1;
    }

    cout << phi << "\n";
    return 0;
}
