class Solution {
   public:
    bool is_opening(char ch) {
        if (ch == '(' || ch == '{' || ch == '[') {
            return true;
        } else {
            return false;
        }
    }

    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (is_opening(ch)) {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    if (ch == ')') {
                        if (st.top() != '(') return false;
                    } else if (ch == '}') {
                        if (st.top() != '{') return false;
                    } else {  // ]
                        if (st.top() != '[') return false;
                    }
                    st.pop();
                }
            }
        }

        if (st.empty()) 
            return true;
        else
            return false;
    }
};
