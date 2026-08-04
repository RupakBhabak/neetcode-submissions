class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        
        for (int i = 0; i < temperatures.size(); i++)
        {
            int count = 0;

            for (int j = i; j < temperatures.size(); j++)
            {
                if (temperatures[j] > temperatures[i])
                    break;

                if (j == temperatures.size() - 1 && temperatures[j] <= temperatures[i])
                {
                    count = 0;
                    break;
                }
 
                ++count;
            }

            ans.push_back(count);
        }

        return ans;
    }
};
