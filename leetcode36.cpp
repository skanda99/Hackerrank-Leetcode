
// problem: "https://leetcode.com/problems/valid-sudoku/"

class Solution {
public:

    bool checkRow(vector<vector<char>>&B)
    {
        int i,j;
        for(i=0;i!=9;i++)
        {
            unordered_set<char>S;
            for(j=0;j!=9;j++)
            {
                if(B[i][j] != '.' && S.find(B[i][j]) != S.end())
                    return false;

                S.insert(B[i][j]);
            }
        }

        return true;
    }

    bool checkColumn(vector<vector<char>>&B)
    {
        int i,j;
        for(j=0;j!=9;j++)
        {
            unordered_set<char>S;
            for(i=0;i!=9;i++)
            {
                if(B[i][j] != '.' && S.find(B[i][j]) != S.end())
                    return false;

                S.insert(B[i][j]);
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
                unordered_set<char>S;
                for(i=k;i<k+3;i++)
                {
                    for(j=l;j<l+3;j++)
                    {
                        if(B[i][j] != '.' && S.find(B[i][j]) != S.end())
                            return false;

                        S.insert(B[i][j]);
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
