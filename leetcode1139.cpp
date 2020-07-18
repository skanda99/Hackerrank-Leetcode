
// problem: "https://leetcode.com/problems/largest-1-bordered-square/"

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        
        int n,m;
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>>R(n,vector<int>(m+1));
        vector<vector<int>>D(n+1,vector<int>(m));
        
        int i,j;
        for(i=0;i!=n;i++)
            for(j=m-1;j>=0;j--)
                if(grid[i][j])
                    R[i][j] = R[i][j+1]+1;
        
        
        for(i=n-1;i>=0;i--)
            for(j=0;j!=m;j++)
                if(grid[i][j])
                   D[i][j] = D[i+1][j]+1;
        
        int l,M;
        M = 0;
        for(i=0;i!=n;i++)
        {
            for(j=0;j!=m;j++)
            {
                if(grid[i][j])
                {
                    l = min(R[i][j],D[i][j]);
                    
                    while(l)
                    {
                        int i1,j1,i2,j2;
                        i1 = i;
                        j1 = j+l-1;
                        
                        i2 = i+l-1;
                        j2 = j;
                        
                        if(R[i2][j2] >= l && D[i1][j1] >= l)
                        {
                            M = max(M,l*l);
                            break;
                        }
                        
                        l--;
                    }
                }
            }
        }
        
        return M;
    }
};
