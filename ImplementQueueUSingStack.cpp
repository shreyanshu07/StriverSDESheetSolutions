class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        this->s1.push(x);
    }
    
    int pop() {
        while(!this->s1.empty()){
            this->s2.push(this->s1.top());
            this->s1.pop();
        }
        int ans=this->s2.top();
        this->s2.pop();
        while(!this->s2.empty()){
            this->s1.push(this->s2.top());
            this->s2.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!this->s1.empty()){
            this->s2.push(this->s1.top());
            this->s1.pop();
        }
        int ans=this->s2.top();
        while(!this->s2.empty()){
            this->s1.push(this->s2.top());
            this->s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return this->s1.empty();
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
