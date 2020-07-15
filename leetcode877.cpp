
//problem: "https://leetcode.com/problems/stone-game/"

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int T = 0;
        for(int i: piles)
            T += i;
        
        vector<vector<int>>V(n,vector<int>(n,-1));
        
        if(getScores(0,n-1,piles,V,1) > T/2)
            return true;
        
        return false;
    }
    
    int getScores(int i,int j,vector<int>&piles,vector<vector<int>>&V,int p)
    {
        if(i > j)
            return 0;
        
        if(V[i][j] == -1)
        {
            if(p)
                V[i][j] = max(getScores(i+1,j,piles,V,0)+piles[i], getScores(i,j-1,piles,V,0)+piles[j]);
            
            else
                V[i][j] = min(getScores(i+1,j,piles,V,1)+piles[i], getScores(i,j-1,piles,V,1)+piles[j]);
        }
        
        return V[i][j];
    }
};
