
// problem: "https://leetcode.com/problems/guess-number-higher-or-lower-ii/"

class Solution {
public:
    int getMoneyAmount(int n) {
        
        vector<vector<int>>V(n+1,vector<int>(n+1,-1));
        
        return getMinCost(1,n,V);
    }
    
    int getMinCost(int i,int j,vector<vector<int>>&V)
    {
        if(i >= j)
            return 0;
        
        if(V[i][j] == -1)
        {
            int k;
            V[i][j] = INT_MAX;
            for(k=i;k!=j+1;k++)
                V[i][j] = min(V[i][j],max(getMinCost(i,k-1,V),getMinCost(k+1,j,V))+k);
        }
        
        return V[i][j];
    }
};
