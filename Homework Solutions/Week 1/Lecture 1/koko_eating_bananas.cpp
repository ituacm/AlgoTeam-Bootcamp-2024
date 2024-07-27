// Author: Kemal Tahir Bıcılıoğlu
// Question Link: https://leetcode.com/problems/koko-eating-bananas/description/

// check out why we should use low + (high - low) / 2 for binary search
// https://research.google/blog/extra-extra-read-all-about-it-nearly-all-binary-searches-and-mergesorts-are-broken/

// Time complexity: O(n logM), M is the largest element in the array.
// Space complexity: O(1)

class Solution {
public:
    bool finish_bananas(const vector<int> &nums, int k, int h){
        long long hours_passed = 0; // hours passed can be too large for some test cases
        for(int pile : nums){
            hours_passed += ceil((double)pile / k);
            // this will calculate hours passed for that pile.
        }
        return hours_passed <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_num = *max_element(piles.begin(), piles.end());
        int high = max_num;
        // koko cannot eat all the bananas less than piles.size() hours.
        // worst scenario is h = piles.size()
        // So, her slowest eating speed for the worst scenario is the maximum pile in the array.
        int low = 1; 
        // minimum eating speed is 1
        
        // binary search for eating speed. We know upper limit and lower limit
        // this is called binary search on answer.
        // We can decide if eating speed is enough or not and change it accordingly.
        while(low <= high){
            int k = low + ((high - low) / 2); // check the article link above
            if(finish_bananas(piles, k, h)){
                high = k - 1;
                // if we can finish, search for the minimum eating speed
            }else{
                low = k + 1;
                // if we cannot finish, search for k that we can finish
            }
        }
        // answer will be low since we keep getting lower k's that satisfies the hours.
        return low;
    }
};
