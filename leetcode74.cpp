
// problem: "https://leetcode.com/problems/search-a-2d-matrix/"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int target) {
        if(!M.size() || !M[0].size())
            return false;
        
        int i = getRow(0,M.size()-1,M,target);
        
        if(i == -1)
            return false;
        
        return findCol(0,M[0].size()-1,M,target,i);
    }
    
    int getRow(int i,int j,vector<vector<int>>&M,int &target)
    {
        if(i > j)
            return j;
        
        int m = (i+j)/2;
        if(M[m][0] == target)
            return m;
        
        else if(M[m][0] < target)
            return getRow(m+1,j,M,target);
        
        return getRow(i,m-1,M,target);
    }
    
    bool findCol(int i,int j,vector<vector<int>>&M,int &target,int &r)
    {
        if(i > j)
            return false;
        
        int m = (i+j)/2;
        if(M[r][m] == target)
            return true;
        else if(M[r][m] < target)
            return findCol(m+1,j,M,target,r);
        
        return findCol(i,m-1,M,target,r);
    }
};
