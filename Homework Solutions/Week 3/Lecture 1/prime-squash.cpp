// Author: Murat Biberoglu
// Question Link: https://algoleague.com/problem/prime-squash

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll maxn = 1e7;  // Maximum limit for the sieve

// Function to generate a sieve of Eratosthenes
vector<bool> sieve() {
    vector<bool> isPrime(maxn + 1, true);  // Initialize a boolean vector to mark primes
    isPrime[0] = isPrime[1] = false;       // 0 and 1 are not prime numbers

    // Mark non-prime numbers using the sieve of Eratosthenes
    for (ll p = 2; p * p <= maxn; p++) {
        if (isPrime[p] == true) {                  // If p is prime
            for (ll i = p * p; i <= maxn; i += p)  // Mark multiples of p as non-prime
                isPrime[i] = false;
        }
    }
    return isPrime;  // Return the vector marking prime numbers
}

void solve() {
    ll n, k;
    cin >> n >> k;  // Read the size of the array and the maximum allowed distinct primes

    vector<ll> numbers(n);  // Array to store input numbers
    for (auto& number : numbers)
        cin >> number;  // Read the numbers into the array

    vector<bool> isPrime = sieve();  // Generate the prime sieve

    unordered_map<ll, ll> primeCountMap;  // Map to count occurrences of each prime in the current window
    ll fast = 0, slow = 0;                // Two pointers for sliding window
    ll primeCount = 0;                    // Count of distinct primes in the current window
    ll answer = 0;                        // Variable to store the final answer

    // Iterate over the array with the fast pointer
    for (fast = 0; fast < n; fast++) {
        ll fastNumber = numbers[fast];  // Current number in the fast pointer

        // If the number is prime
        if (isPrime[fastNumber]) {
            primeCountMap[fastNumber]++;  // Increment the count of this prime in the map
            if (primeCountMap[fastNumber] == 1)
                primeCount++;  // Increment the distinct prime count if it's the first occurrence
        }

        // Adjust the window with the slow pointer if the number of distinct primes exceeds k
        if (primeCount > k) {
            while (primeCount > k && slow < fast) {
                ll slowNumber = numbers[slow];  // Current number in the slow pointer
                if (isPrime[slowNumber]) {
                    primeCountMap[slowNumber]--;  // Decrement the count of this prime in the map
                    if (primeCountMap[slowNumber] == 0)
                        primeCount--;  // Decrement the distinct prime count if its count reaches 0
                }
                slow++;  // Move the slow pointer to the right
            }
        }

        // Count the number of valid subarrays ending at the fast pointer
        answer += fast - slow + 1;
    }

    cout << answer << "\n";  // Output the final answer
}

int32_t main() {
    ios::sync_with_stdio(0);  // Optimize input/output streams
    cin.tie(0);
    cout.tie(0);

    solve();  // Execute the solve function

    return EXIT_SUCCESS;  // Return success
}
