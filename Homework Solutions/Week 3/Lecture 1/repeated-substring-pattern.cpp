// Author: Rojen Arda Sesen
// Question Link: https://leetcode.com/problems/repeated-substring-pattern/

// Time Complexity: O(n)
// Space Complexity: O(2n)

/*
    We will concatenate the string with itself (creating doubledS).
    and remove the first and last characters from this concatenated string.
    Then, if the original string exists as a substring in the new string,
    then s can be formed by repeating a substring.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubledS = s + s;
        //   `substr` member function creates a substring given the start and end positions
        // on a string. This way we can create a string with the first and last
        // characters removed.
        //  `find` member function is used to search a string in another string. If the
        // substring is found, it returns the index of the first occurence of the substring.
        // If it is not found, it returns string::npos, which is used as the end of the string
        // indicater by functions (see https://en.cppreference.com/w/cpp/string/basic_string/npos) 
        return doubledS.substr(1, doubledS.size() - 2).find(s) != string::npos;
    }
};

/*
    Example 1:
    Input: s = "abab"
    - Concatenate the string with itself (abababab) and remove
    the first and last characters: "bababa"
    - Check if "abab" exists in "bababa": 
    Output: true

    Example 2:
    Input: s = "aba"
    Process:
    - Concatenate the string with itself and remove
    the first and last characters: "baab"
    - Check if "aba" exists in "baab": 
    Output: false

    Example 3:
    Input: s = "abcabcabcabc"
    Process:
    - Concatenate the string with itself and remove
    the first and last characters: "bcabcabcabcabcabcabcab"
    - Check if "abcabcabcabc" exists in "bcabcabcabcabcabcabcab":
    Output: true

    Example 4:
    Input: s = "abcd"
    - Concatenate the string with itself and remove
    the first and last characters: "bcdabc"
    - Check if "abcd" exists in "bcdabc": 
    Output: false
*/
