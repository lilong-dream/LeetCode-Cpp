
// TODO
// Queue

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        st1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(st2.empty()) {
             while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
           
        st2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(st2.empty()) {
             while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
           
        return st2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st1.empty() && st2.empty();
    }
private:
    std::stack<int> st1;
    std::stack<int> st2;
};

