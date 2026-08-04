class Solution {
   public:
    bool can_collide(int a, int b) {
        if (a > 0 && b < 0)
            return true;
        else
            return false;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans(0);
        stack<int> st;

        for (int a : asteroids) {
            bool alive = true;

            while (alive && !st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();
                } else if (abs(st.top()) == abs(a)) {
                    st.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }

            if (alive) st.push(a);
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        int i = 0, j = ans.size() - 1;

        while (i < j)
        {
            swap(ans[i], ans[j]);
            i++; j--;
        }

        return ans;
    }
};