
// problem: "https://leetcode.com/problems/search-a-2d-matrix-ii/"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int target) {
        
        if(M.empty() || M[0].empty())
            return false;
        
        if(M.size() > M[0].size())
        {
            int i,j;
            for(j=0;j!=M[0].size();j++)
                if(binarySearchRow(0,M.size()-1,M,target,j))
                    return true;
        }
        else
        {
            int i,j;
            for(i=0;i!=M.size();i++)
                if(binarySearchCol(0,M[0].size()-1,M,target,i))
                    return true;
        }
        
        return false;
    }
    
    bool binarySearchRow(int i,int j,vector<vector<int>>&M,int &target,int &c)
    {
        if(i > j)
            return false;
        
        int m = (i+j)/2;
        
        if(M[m][c] == target)
            return true;
        
        else if(M[m][c] < target)
            return binarySearchRow(m+1,j,M,target,c);
        
        return binarySearchRow(i,m-1,M,target,c);
    }
    
    bool binarySearchCol(int i,int j,vector<vector<int>>&M,int &target,int &r)
    {
        if(i > j)
            return false;
        
        int m = (i+j)/2;
        
        if(M[r][m] == target)
            return true;
        
        else if(M[r][m] < target)
            return binarySearchCol(m+1,j,M,target,r);
        
        return binarySearchCol(i,m-1,M,target,r);
    }
    
};
