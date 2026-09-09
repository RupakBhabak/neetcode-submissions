class Solution
{
public:
    void count_freq_and_put_on_heap(vector<char> &tasks, priority_queue<int> &pq)
    {
        unordered_map<char, int> m;

        for (const char &task : tasks)
        {
            m[task]++;
        }

        for (const auto &elem : m)
        {
            pq.push(elem.second);
        }
    }

    int leastInterval(vector<char> &tasks, int n)
    {
        priority_queue<int> pq; 
        queue<pair<int, int>> q; // queue -> (freq, nextAvalTime)
        int time = 0;

        count_freq_and_put_on_heap(tasks, pq);

        while (!pq.empty() || !q.empty())
        {
            time++;

            if (!pq.empty())
            {
                int freq = pq.top() - 1;
                pq.pop();
                if (freq > 0)
                {
                    q.push({freq, time + n});
                }
            }
            
            else if (!q.empty())
            {
                time = q.front().second;
            }

            if (!q.empty() && q.front().second == time)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};