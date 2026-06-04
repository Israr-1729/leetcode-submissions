class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++)
        {
            set<char> isSeen;
            for(int j = 0; j<9; j++)
            {
                if(board[i][j]=='.')
                continue;
                if(isSeen.find(board[i][j])!=isSeen.end())
                return false;
                isSeen.insert(board[i][j]);
            }
        }
        for(int i = 0; i<9; i++)
        {
            set<char> isSeen;
            for(int j = 0; j<9; j++)
            {
                if(board[j][i]=='.')
                continue;
                if(isSeen.find(board[j][i])!=isSeen.end())
                return false;
                isSeen.insert(board[j][i]);
            }
        }

for(int row = 0; row < 9; row += 3)
{
    for(int col = 0; col < 9; col += 3)
    {
        set<char> isSeen;

        for(int i = row; i < row + 3; i++)
        {
            for(int j = col; j < col + 3; j++)
            {
                if(board[i][j] == '.')
                    continue;

                if(isSeen.find(board[i][j]) != isSeen.end())
                    return false;

                isSeen.insert(board[i][j]);
            }
        }
    }
}
        return true;
    }
};