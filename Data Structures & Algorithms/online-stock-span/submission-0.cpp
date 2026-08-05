class StockSpanner {
private:
    vector<int> vec;
public:
    StockSpanner() {
        return;
    }
    
    int next(int price) {
        vec.push_back(price);

        int i = vec.size() - 1, count = 0;

        while (i >= 0)
        {
            if (vec[i] <= price)
                ++count;
            else
                break;
            --i;
        }

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */