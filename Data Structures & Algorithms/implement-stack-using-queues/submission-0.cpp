class MyStack {
private:
    queue<int> Q1, Q2;

public:
    MyStack() {}
    
    void push(int x) {
        Q1.push(x);
    }
    
    int pop() {
        while (Q1.size() != 1) {
            Q2.push(Q1.front());
            Q1.pop();
        }

        int temp = Q1.front();
        Q1.pop();

        while (!Q2.empty()) {
            Q1.push(Q2.front());
            Q2.pop();
        }

        return temp;
    }
    
    int top() {
        while (Q1.size() != 1) {
            Q2.push(Q1.front());
            Q1.pop();
        }

        int temp = Q1.front();
        Q2.push(Q1.front());
        Q1.pop();

        while (!Q2.empty()) {
            Q1.push(Q2.front());
            Q2.pop();
        }

        return temp;
    }
    
    bool empty() {
        return Q1.size() == 0;
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