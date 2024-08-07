// Author: Anıl Dervişoğlu
// Question Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/

/* There are other solution methods as well but the following editorial
 * uses queue as emphasized in the homework. Our idea here is to
 * make a queue consisting of 'n' numbers from '1' to 'n', then getting the
 * first element to the last in the queue for 'k' times and deleting the next one
 * until there is '1' element left in the queue.
 */

class Solution {
public:
    int findTheWinner(int n, int k)
    {
        queue<int> numbers;
    
    	for(int i = 1; i <= n; ++i)
            numbers.push(i);

        while(numbers.size() != 1)
        {
            for(int i = 1; i < k; ++i)
	    {
                numbers.push(numbers.front());
                numbers.pop();
            }
            numbers.pop();
        }

        return numbers.front();
    }
};
