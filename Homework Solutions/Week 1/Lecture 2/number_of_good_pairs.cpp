// Author: Kemal Tahir Bıcılıoğlu
// Question link: https://leetcode.com/problems/number-of-good-pairs/

/*
    We can use a map to count each number's occurences in the array. We are asked to 
    find nums[i] == nums[j] pairs. Combination with 2 of the number of occurence of 
    an integer in the array will give all the good pairs in the array. We need to count
    all the good pairs.
*/

// Time complexity: O(n)
// Space complexity: O(n)
/*  
    Note: inserting an element to the unordered map is O(1) in average case and O(n)
    in the worst case because of the possibilty of collisions. If we used map instead of 
    unordered map, complexity would be O(n logn). Usually using unordered map is faster.
*/

class Solution {
public:
    int combination_with_two(int num){
        return (num * (num-1)) / 2;
    }

    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> count_pairs;
        
        for(auto num : nums){
            count_pairs[num]++;
        }
        // map will be {1,3}, {2,1}, {3,2} for the example 1.
        
        int ans = 0;
        for(auto it : count_pairs){
            ans += combination_with_two(it.second);
        }
        // for example 1: (3*2/2)+(1*0/2)+(2*1/2) = 4.
        return ans;
    }
};
