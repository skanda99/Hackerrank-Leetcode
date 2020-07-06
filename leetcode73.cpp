
// problem: "https://leetcode.com/problems/set-matrix-zeroes/"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int k1,k2;
        k1 = INT_MIN+1;
        k2 = INT_MAX-1;
        
        int i,j;
        for(i=0;i!=matrix.size();i++)
            for(j=0;j!=matrix[i].size();j++)
                if(!matrix[i][j])
                {
                    makeRow(matrix,i,k1,i,j);
                    makeCol(matrix,j,k2,i,j);
                }
        
        for(i=0;i!=matrix.size();i++)
            for(j=0;j!=matrix[i].size();j++)
                if(matrix[i][j] == k1 || matrix[i][j] == k2)
                    matrix[i][j] = 0;
    }
    
    void makeRow(vector<vector<int>>&matrix,int r,int k,int I,int J)
    {
        if(J-1 >= 0 && (matrix[I][J-1] == k || matrix[I][J-1] == 0))
            return;
        
        int i;
        for(i=0;i!=matrix[r].size();i++)
            if(matrix[r][i] != 0)
                matrix[r][i] = k;
    }
    
    void makeCol(vector<vector<int>>&matrix,int c,int k,int I,int J)
    {
        if(I-1 >= 0 && (matrix[I-1][J] == k || matrix[I-1][J] == 0))
            return;
        
        int i;
        for(i=0;i!=matrix.size();i++)
            if(matrix[i][c] != 0)
                matrix[i][c] = k;
    }
};
