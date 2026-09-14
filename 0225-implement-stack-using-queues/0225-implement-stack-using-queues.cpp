class MyStack {
public:
 queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        int n=q.size();
        q.push(x);

        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
       int top=q.front();
       q.pop();

       return top; 
    }
    
    int top() {
        int t=q.front();

        return t;
    }
    
    bool empty() {
        if(!q.empty()){
            return false;
        }

        return true;
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