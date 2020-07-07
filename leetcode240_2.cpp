
// problem: "https://leetcode.com/problems/search-a-2d-matrix-ii/"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        
        //return search2D(matrix.size()-1,0,matrix,target);
        
        int i,j,n;
        i = matrix.size()-1;
        n = matrix[0].size();
        j = 0;
        
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] == target)
                return true;
            
            else if(matrix[i][j] < target)
                j++;
            else
                i--;
        }
        
        return false;
    }
    
    bool search2D(int i,int j,vector<vector<int>>&M,int &target)
    {
        if(i < 0 || j >= M[0].size())
            return false;
        
        if(M[i][j] == target)
            return true;
        
        else if(M[i][j] < target)
            return search2D(i,j+1,M,target);
        
        return search2D(i-1,j,M,target);
    }
};
