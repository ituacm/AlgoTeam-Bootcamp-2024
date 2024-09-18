// Author: Ali Emre Kaya

// Time Complexity: O(m) = O(tasks.size())
// Space Complexity: O(1)

/*
The push operation takes O(log 26) time, which is a constant, and does not affect the overall time complexity.
The N cooldown time affects the overall number of operations but remains linear in terms of time complexity. 
The vector, queue, and priority queue have a maximum size of 26, which is also constant, so space complexity remains O(1).
*/

/*
Approach:
This solution schedules tasks by first counting their frequencies and then using a max-heap (priority queue) 
to prioritize and execute the most frequent tasks. A cooldown queue manages tasks that can't be immediately 
repeated due to the cooldown period. The process continues until all tasks are completed, and the total 
time taken is returned.
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Count the frequency of each task
        vector<int> taskmap(26,0);
        for(auto t : tasks) {
            // 'A' - 'A' = 0
            // 'Z' - 'A' = 25
            taskmap[t - 'A']++;
        }

        // Use a max-heap (priority queue) to process tasks by their frequency
        priority_queue<int> heap;
        for(auto c : taskmap) {
            if(c > 0) {
                heap.push(c); 
            }
        }

        // Queue to manage the cooldown period
        queue<pair<int,int>> cooldown;
        int time = 0;

        // Process until all tasks are completed
        while (!heap.empty() || !cooldown.empty()) {
            time++; 

            if (!heap.empty()) {
                int current = heap.top();
                heap.pop();
                current--; // One instance of the task completed
                if (current > 0) {
                    // Schedule for next possible execution
                    cooldown.push({current, time + n});
                }
            }

            // Check if any task in cooldown is ready to be re-added to the heap
            pair<int, int> task = cooldown.front();
            if (!cooldown.empty() && task.second == time) {
                heap.push(task.first);
                cooldown.pop();
            }
        }

        return time;
    }
};