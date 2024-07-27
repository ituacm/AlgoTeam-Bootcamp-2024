// Fatih Baskın
// Question Link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

class Solution
{
public:
    // This function checks if a given string is a palindrome
    bool isPalindrome(const string &word)
    {
        /**
         * You need to check from i = 0 to n/2 (not including n/2) where n is the number of characters in the string.
         * i and n-i-1 should be matching characters for the string to be a palindrome.
         *
         * If n = 5, then this logic will check:
         * word[0] == word[4]
         * word[1] == word[3]
         * word[2] == word[2]
         *
         * If n = 6, then this logic will check:
         * word[0] == word[5]
         * word[1] == word[4]
         * word[2] == word[3]
         *
         */
        // Number of characters in the string
        int n = word.size();
        for (int i = 0; i < n / 2; i++)
        {
            // If the characters at the two ends of the string are different, then the string is not a palindrome
            if (word[i] != word[n - i - 1])
                return false;
        }
        return true;
    }

    string firstPalindrome(vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
            // Check every string in the input vector to see if it is a palindrome
            if (isPalindrome(words[i]))
                // If a palindrome is found, return it
                return words[i];
        // If no palindrome is found, return an empty string
        return "";
    }
};
