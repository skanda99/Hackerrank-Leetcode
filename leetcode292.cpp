
// problem: "https://leetcode.com/problems/nim-game/"

class Solution {
public:
    
    bool canWinNim(int n)
    {
        // check pattern in DP solution
        return n%4;
    }
    
    /*
    
    DP solution
    
    bool canWinNim(int n) {
        
        if(n < 4)
            return true;
        
        vector<vector<bool>>V(n+1,vector<bool>(2,-1));
        int i,j;
        
        V[1][0] = V[2][0] = V[3][0] = false;
        V[1][1] = V[2][1] = V[3][1] = true;
        
        for(i=4;i<=n;i++)
        {
            V[i][0] = V[i-1][1] && V[i-2][1] && V[i-3][1];
            V[i][1] = V[i-1][0] || V[i-2][0] || V[i-3][0];
        }
        
        return V[n][1];
    }
    
    */
};
