class Solution {
   public:
    bool is_opening(char ch)
    {
        if (ch == '(' || ch == '{' || ch == '[')
            return true;
        else
            return false;
    }

    bool isValid(string s)
    {
        stack<char> S;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (is_opening(ch))
            {
                S.push(ch);
            }
            else
            {
                if (S.empty())
                    return false;

                if ((S.top() == '(' && ch == ')') || (S.top() == '{' && ch == '}') || (S.top() == '[' && ch == ']'))
                    S.pop();
                else
                    return false;
            }
        }

        if (S.empty())
            return true;
        else
            return false;
    }
};
