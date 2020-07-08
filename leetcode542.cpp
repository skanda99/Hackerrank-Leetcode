
// problem: "https://leetcode.com/problems/01-matrix/"

#define Pair pair<int,int>

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& M) {
        if(M.empty() || M[0].empty())
            return vector<vector<int>>(1,vector<int>());
        
        queue<Pair>Q;
        int i,j,n,m;
        n = M.size();
        m = M[0].size();
        vector<vector<int>>V(n,vector<int>(m,INT_MAX));
        
        for(i=0;i!=n;i++)
            for(j=0;j!=m;j++)
                if(M[i][j] == 0)
                {
                    V[i][j] = 0;
                    Q.push(Pair(i,j));
                }
                    
        while(!Q.empty())
        {
            i = Q.front().first;
            j = Q.front().second;
            Q.pop();
            
            if(i-1 >= 0 && M[i-1][j] && V[i-1][j] == INT_MAX)
            {
                Q.push(Pair(i-1,j));
                V[i-1][j] = V[i][j]+1;
            }
            
            if(i+1 < n && M[i+1][j] && V[i+1][j] == INT_MAX)
            {
                Q.push(Pair(i+1,j));
                V[i+1][j] = V[i][j]+1;
            }
            
            if(j-1 >= 0 && M[i][j-1] && V[i][j-1] == INT_MAX)
            {
                Q.push(Pair(i,j-1));
                V[i][j-1] = V[i][j]+1;
            }

            if(j+1 < m && M[i][j+1] && V[i][j+1] == INT_MAX)
            {
                Q.push(Pair(i,j+1));
                V[i][j+1] = V[i][j]+1;
            }
        }
        
        return V;
    }
};
