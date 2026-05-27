class MyQueue {
private:
    stack<int> S1, S2;

public:
    MyQueue() {}
    
    void push(int x) {
        S1.push(x);
    }
    
    int pop() {
        if (S2.empty()) {
            while (!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }

        int temp = S2.top();
        S2.pop();

        return temp;
    }
    
    int peek() {
        if (S2.empty()) {
            while (!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }

        int temp = S2.top();

        return temp;
    }
    
    bool empty() {
        return S1.size() == 0 && S2.size() == 0;
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