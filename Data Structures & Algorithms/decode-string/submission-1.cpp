class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string res = "";

        for (const char &ch : s)
        {
            string curr;
            curr = ch;

            if (curr != "]")
            {
                st.push(curr);
            }
            else
            {
                string buffer = "", final = "";
                string numStr = "";
                int n;

                while (!st.empty() && st.top() != "[")
                {
                    buffer = st.top() + buffer;
                    st.pop();
                }

                st.pop();

                while (!st.empty() && isdigit(st.top()[0]))
                {
                    numStr = st.top() + numStr;
                    st.pop();
                }

                n = stoi(numStr);

                while (n > 0)
                {
                    final += buffer;
                    n--;
                }

                st.push(final);
            }
        }

        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};