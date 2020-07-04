
// problem: "https://leetcode.com/problems/jump-game-iii/"

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool>Vis(arr.size(),false);
        return dfs(arr,start,Vis);
    }

    bool dfs(vector<int>&V,int i,vector<bool>&Vis)
    {
        if(i < 0 || i >= V.size() || Vis[i])
            return false;

        if(!V[i])
            return true;

        Vis[i] = true;

        return dfs(V,i+V[i],Vis) || dfs(V,i-V[i],Vis);
    }
};
