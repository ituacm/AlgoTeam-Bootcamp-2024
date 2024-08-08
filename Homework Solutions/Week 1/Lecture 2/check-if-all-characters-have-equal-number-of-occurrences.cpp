// Ali Kemal Coşkun
// Question Link: https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }

        // Get the count of the first character
        // You do not need to check all the occurrences one by one
        int count = charCount[s[0]];

        // Iterator
        auto it = charCount.begin();

        while (it != charCount.end()) {
            if (it->second != count) {
                return false;
            }
            it++;
        }

        return true;
    }
};