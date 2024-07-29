// Author: Kemal Tahir Bıcılıoğlu
// Question link: https://leetcode.com/problems/implement-queue-using-stacks/

/*
    Basic approach is using the first stack as pushing elements and to get the "front" element
    for queue implementation, pushing all the elements in the first stack to the second one
    and getting the front element and reversing back all the elements in the first stack.
    This makes O(1) push, O(2n) = O(n) pop. For peek we should again transfer the numbers
    to the second stack and get the top element, which is O(n). For empty, basically check
    if the first stack is empty or not, which is O(1). This is a solid and okey solution for
    this problem however we can improve some of the approaches. How?
*/
/*
    Using second stack temporarily and transfer back the numbers to the first stack
    when peek and pop is done is not very efficient. What if we use second stack as
    like queue (First in First out) (because we have "First In" values in the stack
    from top to bottom in the correct order) and do the pop and peek operations
    directly from there. This makes O(1) time complexity when the second stack
    (consider as our queue right now) is not empty because we have the "first in"
    element at to top of the stack. What happens second stack is empty? In that case
    We need to push the elements from first stack to second stack so that we have the 
    same structure again. Now we can use the first stack for the push operation, and 
    use the second stack for the pop and peek operations. Since pushing elements from 
    the first stack to the second stack is not necessary in many of the cases, this 
    makes the process amortized O(1). So we have O(1) push, pop and peek. 
    There is a little trick for the peek function. If pop is not called and push is called
    many times in a row, peek does not change. Also think the situation that second stack
    is empty. How are we going to detect the peek element? Do we have to push all the elements
    to the second stack for peek function calls? Actually no. We keep the first pushed element
    into the stack (which is the peek element for the queue, First in) in a variable so that
    we do not have to transfer the numbers to the second stack. Additionally, we have O(1) access
    to the peek when the second stack is not empty.  
*/
// Time complexities:
// push(), O(1)
// pop(), O(1) amortized
// peek(), O(1)
// empty(), O(1)

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int peek_element;
    MyQueue() {
        peek_element = INT_MIN;
    }
    
    void push(int x) {
        if(s1.empty()){
            peek_element = x;
        }
        s1.push(x); // push in O(1)
    }
    
    int pop() { // if s2 is not empty, think it as our queue.
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int popped_element = s2.top();
        s2.pop();
        return popped_element;
    }
    
    int peek() { // if s2 is not empty, think it as our queue.
        if(!s2.empty())
            return s2.top();

        return peek_element; 
        // if s2 is empty, we kept the peek element when the first element is pushed. Use it.
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
