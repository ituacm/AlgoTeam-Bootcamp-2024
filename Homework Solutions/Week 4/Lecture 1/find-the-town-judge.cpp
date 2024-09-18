// Author: Ali Emre Kaya
// Reviewer: Anıl Dervişoğlu
// Question link: https://leetcode.com/problems/find-the-town-judge

// Time complexity: O(n)
// Space complexity: O(n)

/*
Approach: 
The problem can be solved efficiently using a single array to track the trust relationships.

We iterate through the trust array, and for each pair, 
we decrement the score of the person who trusts someone and increment the score of the person who is trusted. 

The decrement ensures that the person who trusts someone cannot be the judge. 
The increment reflects how much others trust the person.
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Initalize a trustCount for everyone
        vector<int> trustCounter(n + 1, 0); 

        for (int i = 0; i < trust.size(); i++) {
            // Decrease trust score for the person who trusts someone
            // this is enaugh to prevent this person is the judge       
            trustCounter[trust[i][0]]--;
            // Increase trust score for the person who is trusted
            trustCounter[trust[i][1]]++; 
        }

        // Check if there is a person with a trust score of n-1,
        // We can sure there is only one person with that truth score thank to decrease operation.
        // If noone's truth value is n-1, then return -1
        for (int i = 1; i <= n; ++i) {
            if (trustCounter[i] == n - 1) {
                return i;
            }
        }
        return -1; 
    }
};