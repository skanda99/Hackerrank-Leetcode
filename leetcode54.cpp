
// problem: "https://leetcode.com/problems/spiral-matrix/"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>V;
        
        if(matrix.empty())
            return V;
        
        getV(matrix,0,0,0,matrix.size(),matrix[0].size(),V);
        return V;
    }
    
    void getV(vector<vector<int>>&M,int i,int j,int state,int m,int n,vector<int>&V)
    {
        V.push_back(M[i][j]);
        M[i][j] = INT_MAX;
        
        if(state == 0)
        {
            if(j+1 < n && M[i][j+1] != INT_MAX)
                getV(M,i,j+1,0,m,n,V);
            else if(i+1 < m && M[i+1][j] != INT_MAX)
                getV(M,i+1,j,1,m,n,V);
        }
        else if(state == 1)
        {
            if(i+1 < m && M[i+1][j] != INT_MAX)
                getV(M,i+1,j,1,m,n,V);
            else if(j-1 >= 0 && M[i][j-1] != INT_MAX)
                getV(M,i,j-1,2,m,n,V);
        }
        else if(state == 2)
        {
            if(j-1 >= 0 && M[i][j-1] != INT_MAX)
                getV(M,i,j-1,2,m,n,V);
            else if(i-1 >= 0 && M[i-1][j] != INT_MAX)
                getV(M,i-1,j,3,m,n,V);
        }
        else
        {
            if(i-1 >= 0 && M[i-1][j] != INT_MAX)
                getV(M,i-1,j,3,m,n,V);
            else if(j+1 < n && M[i][j+1] != INT_MAX)
                getV(M,i,j+1,0,m,n,V);
        }
    }
};
