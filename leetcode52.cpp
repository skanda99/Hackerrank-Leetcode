
// problem: "https://leetcode.com/problems/n-queens-ii/"

#define Pair pair<int,int>

class Solution {
public:
    int totalNQueens(int n) {
        
        vector<vector<string>>psol;
        
        if(!n)
            return 0;
        
        vector<vector<Pair>>V;
        getC(0,0,n,vector<Pair>(),V);
        
        return V.size();
    }
    
    void getC(int i,int j,int n,vector<Pair>sol,vector<vector<Pair>>&V)
    {
        if(i >= n || j >= n)
        {
            if(sol.size() == n)
                V.push_back(sol);
            
            return;
        }
        
        if(isValid(i,j,sol))
        {
            vector<Pair>sol_copy(sol);
            
            sol.push_back(Pair(i,j));
            getC(i+1,0,n,sol,V);
            
            getC(i,j+1,n,sol_copy,V);
        }
        else
            getC(i,j+1,n,sol,V);
    }
    
    bool isValid(int i,int j,vector<Pair>&sol)
    {
        int k;
        for(k=0;k!=sol.size();k++)
        {
            if(i == sol[k].first)
                return false;
            
            if(j == sol[k].second)
                return false;
            
            if(sol[k].first-sol[k].second == i-j)
                return false;
            
            if(sol[k].first + sol[k].second == i+j)
                return false;
        }
        
        return true;
    }
    
};
