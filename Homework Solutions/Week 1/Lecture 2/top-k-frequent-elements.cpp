// Author: Anıl Dervişoğlu
// Question Link: https://leetcode.com/problems/top-k-frequent-elements/

/* There are many solutions but the expected solution required the usage
 * of priority queue like the following editorial. Our idea here is to
 * count the frequency of different elements using unordered_map first,
 * then pushing these variables into priority_queue, and finally
 * getting the top k elements and returning them.
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        priority_queue<pair<int, int>> q;
        vector<int> result;

        for (auto i : nums)
            mp[i]++;

	for (auto i : mp)
            q.push({i.second, i.first});

	for (int i = 0; i < k; i++)
        {
            result.push_back(q.top().second);
            q.pop();
        }

	return result;
    }
};
