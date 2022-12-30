class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    MinStack() {
        while(!s.empty())s.pop();
    }
    //Each time we push a value we push the min along with it
    void push(int val) {
        if(s.empty()){
            s.push(val);
            s.push(val);
            return;
        }
        
        if(val < s.top()){
            s.push(val);
            s.push(val);
        } else {
            int x = s.top();
            s.push(val);
            s.push(x);
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        s.pop();
        s.pop();
    }
    
    int top() {
        if(s.empty())
            return -1;
        int x = s.top();
        s.pop();
        int y = s.top();
        s.push(x);
        return y;
    }
    
    int getMin() {
        if(s.empty())
            return -1;
        return s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */