class MinStack {
public:
    stack<int>st;
    priority_queue<int,vector<int>,greater<int>>pq; // 
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        pq.push(val);
        
    }
    
    void pop() {
        int top=st.top();
        st.pop();
       priority_queue<int, vector<int>, greater<int>> temp;

    while (pq.top() != top) {
        temp.push(pq.top());
        pq.pop();
    }

    pq.pop();

    while (!temp.empty()) {
        pq.push(temp.top());
        temp.pop();
    }
    }
    
    int top() {
       int top=st.top();
       return top; 
    }
    
    int getMin() {
        int pqtop=pq.top();
        
        return pqtop;
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