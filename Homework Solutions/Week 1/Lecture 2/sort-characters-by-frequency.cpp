// Author: Ali Emre Kaya

// Time complexity: O(N)
// Space complexity: O(N)
// Question Link: https://leetcode.com/problems/sort-characters-by-frequency

/*
Approach:
To solve this problem, we can use a combination of an unordered map (hashmap) 
    and a max-heap (priority queue) to sort characters by their frequency. 
    The steps are as follows:

1. Use an unordered map (hashmap) to count the frequency of each character in the string.
2. Use a max-heap (priority queue) to store pairs of (frequency, character).
3. Extract characters from the max-heap and construct the result string by appending each character frequency times.
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;        
        priority_queue<pair<int,char>> maxheap; 

        // Time complexity: O(N)
        // Calculate the frequency of each character in the string
        for(char c: s)
            freq[c]++;

        // Time compleixty: O(log(26)) = O(1)
        // Push the frequency and character into the max-heap
        for(auto it: freq)
            // Priority queue sorts by first value
            maxheap.push({it.second,it.first});

        // Time complexity: O(N) 
        // Construct the result string based on character frequency
        string result; 
        while(!maxheap.empty()){
            int count = maxheap.top().first;
            char ch = maxheap.top().second;
            maxheap.pop();

            // Append the character 'count' times to the result string
            result.append(count, ch);
        }
        return result;
    }
};