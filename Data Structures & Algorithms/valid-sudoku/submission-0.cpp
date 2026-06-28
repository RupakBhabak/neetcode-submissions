class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_map<int, int>> rowHash(9); // ith map -> (num, row)
        vector<unordered_map<int, int>> colHash(9); // ith map -> (num, row)

        // there are total of 9 sub-boxes
        // all 9 sub-boxes are coordinated as:
        // (0,0), (0,1), (0,2), (1,0),....., (2,2)
        // we will calculate (row // 3) * 3 + (col // 3)
        // in-order to get unique values: 0, 1, 2,....., 8 (ith sub-box)

        vector<unordered_map<int, int>> subBoxHash(9); // ith map -> (num, row)

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                    continue;

                int currNum = board[row][col] - '0';

                // validate row

                if (rowHash[row].find(currNum) != rowHash[row].end())
                    return false;
                else
                    rowHash[row][currNum] = row;

                // validate column

                if (colHash[col].find(currNum) != colHash[col].end())
                    return false;
                else
                    colHash[col][currNum] = col;

                // validate sub-box

                int subBoxIndx = ((row / 3) * 3) + (col / 3);

                if (subBoxHash[subBoxIndx].find(currNum) != subBoxHash[subBoxIndx].end())
                    return false;
                else
                    subBoxHash[subBoxIndx][currNum] = row;
            }
        }

        return true;
    }
};
