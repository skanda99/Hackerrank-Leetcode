
// problem: "https://leetcode.com/problems/all-paths-from-source-to-target/"

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>V;
        int n = graph.size();
        dfs(0, vector<int>(), V, n-1, graph);
        return V;
    }
    
    void dfs(int p, vector<int>v, vector<vector<int>>&V, int n, vector<vector<int>>&G) {
        v.push_back(p);
        
        if(p == n) {
            V.push_back(v);
            return;
        }
        
        int i;
        for(i=0;i!=G[p].size();i++) {
            dfs(G[p][i], v, V, n, G);
        }
            
    }
};
