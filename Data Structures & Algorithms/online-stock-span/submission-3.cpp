class StockSpanner {
private:
    stack<pair<int, int>> s; // pair -> (price, its span)
public:
    StockSpanner() {
        return;
    }
    
    int next(int price) {
        int span = 1;

        while (!s.empty())
        {
            if (s.top().first <= price)
            {
                span += s.top().second;
                s.pop();
            }
            else
            {
                break;
            }
        }

        s.push(make_pair(price, span));
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */