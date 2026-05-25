class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> record;

        for (string op : operations) {
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
            } else if (op == "C") {
                record.pop();
            } else {  // numbers
                record.push(stoi(op));
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