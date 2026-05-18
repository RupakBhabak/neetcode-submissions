class Solution {
public:
    bool is_panildrome(const string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++; j--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                return is_panildrome(s, i + 1, j) || is_panildrome(s, i, j - 1);
            }
            
            i++; j--;
        }

        return true;
    }
};