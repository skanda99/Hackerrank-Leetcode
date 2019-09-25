
// problem: "https://leetcode.com/problems/valid-sudoku/"

class Solution {
public:

    bool checkRow(vector<vector<char>>&B)
    {
        int i,j;
        for(i=0;i!=9;i++)
        {
            vector<bool>S(9,0);
            for(j=0;j!=9;j++)
            {
                if(B[i][j] != '.' && S[B[i][j]-'1'])
                    return false;

                if(B[i][j] != '.')
                    S[B[i][j]-'1'] = 1;
            }
        }

        return true;
    }

    bool checkColumn(vector<vector<char>>&B)
    {
        int i,j;
        for(j=0;j!=9;j++)
        {
            vector<bool>S(9,0);
            for(i=0;i!=9;i++)
            {
                if(B[i][j] != '.' && S[B[i][j]-'1'])
                    return false;

                if(B[i][j] != '.')
                    S[B[i][j]-'1'] = 1;
            }
        }

        return true;
    }

    bool checkBlock(vector<vector<char>>&B)
    {
        int i,j,k,l;
        for(k=0;k!=9;k+=3)
        {
            for(l=0;l!=9;l+=3)
            {
                vector<bool>S(9,0);
                for(i=k;i<k+3;i++)
                {
                    for(j=l;j<l+3;j++)
                    {
                        if(B[i][j] != '.' && S[B[i][j]-'1'])
                            return false;

                        if(B[i][j] != '.')
                            S[B[i][j]-'1'] = 1;
                    }
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRow(board) && checkColumn(board) && checkBlock(board);
    }
};
