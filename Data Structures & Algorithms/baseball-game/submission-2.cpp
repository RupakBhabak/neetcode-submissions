class Solution {
public:
    bool is_digit(string s) {
        if ((s[0] >= 48 && s[0] <= 57) || s[0] == '-') {
            return true;
        } else {
            return false;
        }
    }

    int calPoints(vector<string>& operations) {
        stack<int> record;
        
        for (string op : operations) {
            if (is_digit(op)) {
                record.push(stoi(op));
            } else {
                if (op == "+") {
                    int sum = 0, temp;

                    temp = record.top();
                    sum += record.top();
                    record.pop();
                    sum += record.top();
                    record.push(temp);
                    record.push(sum);
                } else if (op == "D") {
                    record.push(record.top() * 2);
                } else { // "C"
                    record.pop();
                }
            }
        }

        int score = 0;

        while (!record.empty()) {
            score += record.top();
            record.pop();
        }

        return score;
    }
};