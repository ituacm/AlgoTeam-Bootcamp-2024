// Author: Fatih Baskın
// Question Link: https://algoleague.com/contest/nice-to-math-you/problem/phi/detail

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    // Euclidean algorithm to find gcd of a and b
    // Time complexity: O(log(min(a, b)))

    if (b == 0)
        return a;
    return gcd(b, a % b);

    // return __gcd(a, b); // This is a built-in function in C++ to find gcd of a and b
}

int main()
{
    // Get the numbers
    int n;
    cin >> n;
    vector<ll> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    ll array_gcd = numbers[0];

    // Calculate gcd of all numbers in the array, one by one
    for (int i = 1; i < n; i++)
        array_gcd = gcd(array_gcd, numbers[i]);

    // This is the gcd of all numbers in the array
    cout << array_gcd << "\n";

    return 0;
}
