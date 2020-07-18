
// problem: "https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/"

#define p (int)(1e9+7)

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>>V(d+1,vector<int>(target+1,-1));
        
        return numWays(d,target,f,V);
    }
    
    int numWays(int d,int target,int &f,vector<vector<int>>&V)
    {
        if(target == 0 && d == 0)
            return 1;
        
        if(target <= 0 || d == 0)
            return 0;
        
        if(V[d][target] == -1)
        {
            int i;
            V[d][target] = 0;
            for(i=1;i!=f+1;i++)
                V[d][target] = (V[d][target] + numWays(d-1,target-i,f,V))%p;
        }
        
        return V[d][target];
 
    }
};
