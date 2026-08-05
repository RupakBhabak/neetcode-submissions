class StockSpanner {
private:
    vector<int> vec;
    int prevSpan;
public:
    StockSpanner() {
        prevSpan = 0;
    }
    
    int next(int price) {
        int i = vec.size() - 1, count = 1;

        if (prevSpan && vec[i] <= price)
        {
            i -= prevSpan;
            count += prevSpan;
        }

        while (i >= 0)
        {
            if (vec[i] <= price)
                ++count;
            else
                break;
            --i;
        }

        vec.push_back(price);
        prevSpan = count;
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */