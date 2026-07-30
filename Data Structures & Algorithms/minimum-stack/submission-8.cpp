class MinStack {
private:
    // Change the stack type to long long to prevent subtraction overflow
    stack<long long> S;
    long long min_val;

public:
    MinStack() {
        // No need for explicit return; in a constructor
    }
    
    void push(int val) {
        if (S.empty()) {
            S.push(0);
            min_val = val;
        } else {
            // This subtraction can exceed INT_MAX/INT_MIN, handled safely by long long
            S.push((long long)val - min_val);
            if (val < min_val) {
                min_val = val;
            }
        }
    }
    
    void pop() {
        if (S.empty()) return;

        long long diff = S.top();
        S.pop();
        
        // If the diff is negative, it means this element changed the minimum.
        // We must restore the previous minimum.
        if (diff < 0) {
            min_val = min_val - diff;
        }
    }
    
    int top() {
        long long diff = S.top();
        if (diff > 0) {
            return (int)(diff + min_val);
        } else {
            // If diff <= 0, the actual value pushed was the min_val itself
            return (int)min_val;
        }
    }
    
    int getMin() {
        return (int)min_val;
    }
};