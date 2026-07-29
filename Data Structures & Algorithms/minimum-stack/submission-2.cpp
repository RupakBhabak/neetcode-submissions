class MinStack
{
private:
    stack<int> S1, S2;
    int min;

public:
    MinStack()
    {
        return;
    }

    void push(int val)
    {
        S1.push(val);

        if (S1.size() == 1)
        {
            S2.push(val);
        }
        else
        {
            if (val < S2.top())
                S2.push(val);
            else
                S2.push(S2.top());
        }
    }

    void pop()
    {
        S1.pop();
        S2.pop();
    }

    int top()
    {
        return S1.top();
    }

    int getMin()
    {
        return S2.top();
    }
};