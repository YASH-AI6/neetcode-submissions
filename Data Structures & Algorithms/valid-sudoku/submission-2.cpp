class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string> seen;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.') continue;

                string rowKey =
                    string(1, board[r][c]) + "row" + to_string(r);

                string colKey =
                    string(1, board[r][c]) + "col" + to_string(c);

                string boxKey =
                    string(1, board[r][c]) + "box" +
                    to_string(r / 3) +
                    to_string(c / 3);

                if (seen.count(rowKey) ||
                    seen.count(colKey) ||
                    seen.count(boxKey))
                {
                    return false;
                }

                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }

        return true;
    }
};