
class MinStack {
public:
    void push(int x) {
        st1.push(x);
        if(st2.empty() || x <= st2.top())  // !
        {
            st2.push(x);
        }
    }

    void pop() {
        if(st1.top() == st2.top())
        {
            st2.pop();
        }
        st1.pop();
        
    }

    int top() {
        return st1.top();
    }

    int getMin() {
        return st2.top();        
    }
    
private:
    stack<int> st1;
    stack<int> st2;
};

