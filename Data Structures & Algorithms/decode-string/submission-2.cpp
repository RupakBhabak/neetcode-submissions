class Solution {
public:
    string decodeString(string s) {
        stack<string> strSt; // string stack
        stack<int> dgtSt;    // digit stack
        string curr = "";
        int k = 0;

        for (const char &ch : s)
        {
            if (isdigit(ch))
            {
                k = (k * 10) + (ch - '0');
            }
            else if (ch == '[')
            {
                strSt.push(curr);
                dgtSt.push(k);

                curr = "";
                k = 0;
            }
            else if (ch == ']')
            {
                string temp = curr;
                curr = strSt.top();
                strSt.pop();
                int count = dgtSt.top();
                dgtSt.pop();

                while (count > 0)
                {
                    curr += temp;
                    count--;
                }
            }
            else
            {
                curr += ch;
            }
        }
        
        return curr;
    }
};