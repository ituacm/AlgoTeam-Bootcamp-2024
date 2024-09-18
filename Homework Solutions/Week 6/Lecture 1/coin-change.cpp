// Autohor :Ali Emre Kaya
// Question link: https://leetcode.com/problems/coin-change/

// Time complexity: O(n*m)
// Space complexity: O(n)

/*
Approach:
We use dynamic programming to solve the problem. We create a `dp` array where `dp[j]` 
stores the minimum number of coins needed to make the amount `j`. We initialize 
`dp[0] = 0` since no coins are needed to make 0. The array is initialized with `INT_MAX`
for all other values as placeholders. For each coin, we iterate through all amounts 
from the coin's value up to the target amount `n`, updating `dp[j]` to the minimum 
of its current value and `1 + dp[j - coins[i]]`. Finally, if `dp[n]` is still `INT_MAX`,
it means the amount `n` can't be formed, so we return `-1`; otherwise, we return `dp[n]`.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        // creating the base dp array, with first value set to INT_MAX
        vector<int> dp(n+1, INT_MAX);
        // for 0 money, only 0 paper needed
        dp[0] = 0;

        // coins need to be sorted
        // but in the question each input given with ascending order already
        //sort(begin(coins), end(coins));

        // process dp
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= n; j++) {
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
                }
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};