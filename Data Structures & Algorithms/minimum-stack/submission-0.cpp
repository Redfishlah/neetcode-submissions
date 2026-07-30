class MinStack {
public:
    stack<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        stack<int> tmp;
        int min_ = s.top();
        while(s.size()){
            min_ = min(min_, s.top());
            tmp.push(s.top());
            s.pop();
        }
        while(tmp.size()){
            s.push(tmp.top());
            tmp.pop();
        }
        return min_;
    }
};
