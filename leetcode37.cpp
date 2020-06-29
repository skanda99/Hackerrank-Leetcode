
// problem: "https://leetcode.com/problems/sudoku-solver/"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>>rows(9,vector<bool>(9,false));
        vector<vector<bool>>cols(9,vector<bool>(9,false));
        vector<vector<bool>>blocks(9,vector<bool>(9,false));

        int i,j;
        for(i=0;i!=9;i++)
        {
            for(j=0;j!=9;j++)
            {
                if(board[i][j] != '.')
                {
                    rows[i][board[i][j]-'1'] = true;
                    cols[j][board[i][j]-'1'] = true;
                    blocks[getI(i,j)][board[i][j]-'1'] = true;
                }
            }
        }

        solve(board,0,0,rows,cols,blocks,board);
    }

    bool solve(vector<vector<char>>board_c, int i, int j, vector<vector<bool>>rows, vector<vector<bool>>cols,
                               vector<vector<bool>>blocks,vector<vector<char>>&board) {
        if(board_c[i][j] != '.')
        {
            if(i == 8 && j == 8)
            {
                board = board_c;
                return true;
            }

            if(j+1 < 9)
                return solve(board_c,i,j+1,rows,cols,blocks,board);

            if(j == 8)
                return solve(board_c,i+1,0,rows,cols,blocks,board);
        }

        int k;
        for(k=1;k!=10;k++)
        {
            if(!rows[i][k-1] && !cols[j][k-1] && !blocks[getI(i,j)][k-1])
            {
                board_c[i][j] = '0'+k;
                rows[i][k-1] = true;
                cols[j][k-1] = true;
                blocks[getI(i,j)][k-1] = true;

                if(i == 8 && j == 8)
                {
                    board = board_c;
                    return true;
                }

                if(j+1 < 9 && solve(board_c,i,j+1,rows,cols,blocks,board))
                    return true;

                if(j == 8 && solve(board_c,i+1,0,rows,cols,blocks,board))
                    return true;


                rows[i][k-1] = false;
                cols[j][k-1] = false;
                blocks[getI(i,j)][k-1] = false;
            }
        }

        return false;
    }

    int getI(int i,int j) {
        i = i/3;
        j = j/3;

        return 3*i + j;
    }
};
