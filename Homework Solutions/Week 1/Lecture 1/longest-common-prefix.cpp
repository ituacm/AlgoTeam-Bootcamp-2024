class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            // If there's only one string in the array, return it as the common prefix
            if(strs.size() == 1)
                return strs[0];

            // Find the minimum length among all the strings in the array
            int minLength = INT_MAX;
            for (auto s : strs)
                minLength = min(minLength, (int) s.length());

            // Initialize an empty string to store the common prefix
            string ans = "";
            
            // Loop through each character index up to the minimum string length
            for(int i=0; i < minLength; i++) {
                // Compare characters at the current index across all strings
                for(int j=0; j < (int) strs.size() - 1; j++) {
                    // If a mismatch is found, return the current common prefix
                    if(strs[j][i] != strs[j+1][i])
                        return ans;
                }
                // If all characters at the current index are the same, add the character to the common prefix
                ans = ans + strs[0][i];
            }
            // Return the common prefix found
            return ans;
        }
};
