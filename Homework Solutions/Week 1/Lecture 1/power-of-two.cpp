// Author: Anıl Dervişoğlu
// Question Link: https://leetcode.com/problems/power-of-two/description/

// Time complexity: O(logn)
// Space complexity: O(1)

// The idea behind this problem is to check if the given number is a power of 2.
// If it is, then it should be divisible by 2 and the result should be a power of 2 as well.
// We can recursively check if n is a power of 2 by dividing it by 2 until it reaches 1.
// If n is less than or equal to 0 or n is odd, then it is not a power of 2.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if n has reached to 1 by continuously dividing by 2 and the number wasn't odd along the way, then it is a power of 2.
        if (n == 1)
            return true;
        else if (n <= 0 or n % 2 == 1) // if n is less than or equal to 0 or n is odd, then it is not a power of 2.
            return false;
        else
            return isPowerOfTwo(n / 2); // recursively check if n / 2 is a power of 2, till n reaches 1.
    }
};