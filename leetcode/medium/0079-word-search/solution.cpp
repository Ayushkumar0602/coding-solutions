class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int i, int j, int st) {

        
        if (st == word.size())
            return true;

        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;

        
        if (board[i][j] != word[st])
            return false;

       
        char temp = board[i][j];
        board[i][j] = '#';

        bool ans = solve(board, word, i + 1, j, st + 1) ||
                   solve(board, word, i - 1, j, st + 1) ||
                   solve(board, word, i, j + 1, st + 1) ||
                   solve(board, word, i, j - 1, st + 1);

        
        board[i][j] = temp;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (solve(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};