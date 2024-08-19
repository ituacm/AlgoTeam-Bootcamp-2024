// Author: Murat Biberoglu
// Question Link: https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

class Solution {
public:
    int largestInteger(int num) {
        // stack to track if each digit is odd (true) or even (false)
        stack<bool> isOddDigit;
        // vector of priority queues: index 0 for even digits, index 1 for odd digits
        vector<priority_queue<int>> queues(2);

        // extract digits from the number
        while (num) {
            int d = num % 10;  // get the last digit
            num /= 10;  // remove the last digit from the number
            isOddDigit.push(d % 2);  // push true if digit is odd, false if even
            queues[d % 2].push(d);  // push the digit into the respective priority queue
        }

        // reconstruct the largest possible number with digits of the same parity
        while (!isOddDigit.empty()) {
            // get the top element from the appropriate priority queue
            num = num * 10 + queues[isOddDigit.top()].top();
            queues[isOddDigit.top()].pop();  // remove the top element from the queue
            isOddDigit.pop();  // remove the parity indicator from the stack
        }

        return num;  // return the largest integer possible with same parity digits
    }
};
