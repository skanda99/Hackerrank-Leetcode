
// problem: "https://leetcode.com/problems/as-far-from-land-as-possible/"

#define Pair pair<int, int>

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<Pair>Q;
        int i, j, n;
        n = grid.size();
        vector<vector<int>>V(n, vector<int>(n, -1));
        for(i=0;i!=n;i++) {
            for(j=0;j!=n;j++) {
                if(grid[i][j] == 1) {
                    Q.push(Pair(i, j));
                    V[i][j] = 0;
                }
            }
        }
        
        if(Q.size() == 0 || Q.size() == n*n) {
            return -1;
        }
        
        while(!Q.empty()) {
            Pair p = Q.front();
            Q.pop();
            
            if(p.first-1 >= 0 && V[p.first-1][p.second] == -1) {
                Q.push(Pair(p.first-1, p.second));
                V[p.first-1][p.second] = V[p.first][p.second]+1;
            }
            
            if(p.first+1 < n && V[p.first+1][p.second] == -1) {
                Q.push(Pair(p.first+1, p.second));
                V[p.first+1][p.second] = V[p.first][p.second]+1;                
            }
            
            if(p.second-1 >= 0 && V[p.first][p.second-1] == -1) {
                Q.push(Pair(p.first, p.second-1));
                V[p.first][p.second-1] = V[p.first][p.second]+1;
            }
            
            if(p.second+1 < n && V[p.first][p.second+1] == -1) {
                Q.push(Pair(p.first, p.second+1));
                V[p.first][p.second+1] = V[p.first][p.second]+1;
            }
        }
        
        int m = 0;
        for(i=0;i!=n;i++) {
            for(j=0;j!=n;j++) {
                m = max(m, V[i][j]);
            }
        }
        
        return m;
    }
};
