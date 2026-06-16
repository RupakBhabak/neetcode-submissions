class Solution {
private:
    priority_queue<int> pq;

public:
    int lastStoneWeight(vector<int> &stones)
    {
        for (int stone : stones)
        {
            pq.push(stone);
        }

        int x, y;

        while (pq.size() > 1)
        {
            x = pq.top();
            pq.pop();

            if (!pq.empty())
            {
                y = pq.top();
                pq.pop();

                if (x > y)
                {
                    pq.push(x - y);
                }
            }
            else
                pq.push(x);
        }

        if (pq.empty())
            return 0;
        else
            return pq.top();
    }
};
