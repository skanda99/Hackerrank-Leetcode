
// problem: "https://leetcode.com/problems/rotate-image/"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = (n%2)?n/2+1:n/2;

        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                if(j < m && n-1-i < m)
                    continue;

                rotate90(i,j,0,1,matrix,n);         // define
            }
        }
    }

    void rotate90(int i,int j,int val,int c,vector<vector<int>>&matrix,int n)
    {
        if(c == 6)
            return;

        rotate90(j,n-1-i,matrix[i][j],c+1,matrix,n);

        if(c != 1)
            matrix[i][j] = val;
    }
};
