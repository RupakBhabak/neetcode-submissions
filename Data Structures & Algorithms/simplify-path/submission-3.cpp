class Solution {
public:
    string simplifyPath(string path) { 
        const int n = path.size();
        vector<string> st;
        string buffer = "", ans = "";
        int i = 0;
        path += "/";

        for (const char ch : path)
        {
            if (ch == '/')
            {
                if (buffer == "..")
                {
                    if (!st.empty())
                    {
                        st.pop_back();
                    }
                }
                else if (!buffer.empty() && buffer != ".")
                {
                    st.push_back(buffer);
                }

                buffer = "";
            }
            else
            {
                buffer += ch;
            }
        }

        if (st.empty())
            return "/";

        for (string &dir: st)
        {
            ans = ans + "/" + dir;
        }

        return ans;
    }
};