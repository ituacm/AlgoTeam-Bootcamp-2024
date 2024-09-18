// Ali Kemal Coşkun
// Question Link: https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
private: // SUGGESTION: Make the members private
    queue<int> masterQueue;
    queue<int> tempQueue;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        tempQueue.push(x);
        while (!masterQueue.empty()) {
            tempQueue.push(masterQueue.front());
            masterQueue.pop();
        }

        // Example:
        // tempQueue = Back {1} Front
        // masterQueue = Back {5, 4, 3, 2} Front <- Stack view
        //
        // After the while loop, tempQueue = Back {5, 4, 3, 2, 1} Front <- Stack view
        // masterQueue = {}
        // Swap the queues to maintain the stack view

        swap(masterQueue, tempQueue);
    }
    
    int pop() {
        int top = masterQueue.front();
        masterQueue.pop();
        return top;
    }
    
    int top() {
        return masterQueue.front();
    }
    
    bool empty() {
        return masterQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */