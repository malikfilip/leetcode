class MinStack {
public:
    stack<int> localStack;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int val) {
        if(localStack.empty() || val <= mins.top()){ 
            mins.push(val);
        }
        
        localStack.push(val);
    }
    
    void pop() {
        if(localStack.empty())return;
        if(localStack.top() == mins.top())mins.pop();
        localStack.pop();
    }
    
    int top() {
        if(localStack.empty())return -1;
        return localStack.top();
    }
    
    int getMin() {
        if(localStack.empty())return -1;
        return mins.top();
    }
};
