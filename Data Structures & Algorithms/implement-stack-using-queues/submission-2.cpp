class MyStack {
private:
    queue<int> Q;

public:
    MyStack() {}
    
    void push(int x) {
        Q.push(x);
    }
    
    int pop() {
        for (int i = 0; i < Q.size() - 1; i++) {
            Q.push(Q.front());
            Q.pop();
        }

        int temp = Q.front();
        Q.pop();

        return temp;
    }
    
    int top() {
        for (int i = 0; i < Q.size() - 1; i++) {
            Q.push(Q.front());
            Q.pop();
        }

        int temp = Q.front();
        Q.push(Q.front());
        Q.pop();

        return temp;
    }
    
    bool empty() {
        return Q.size() == 0;
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