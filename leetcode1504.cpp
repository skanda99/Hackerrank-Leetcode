
// problem: "https://leetcode.com/problems/count-submatrices-with-all-ones/"

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        int n,m;
        n = mat.size();
        m = mat[0].size();
        
        int i,j;
        for(i=n-2;i>=0;i--)
            for(j=0;j!=m;j++)
                if(mat[i][j])
                    mat[i][j] += mat[i+1][j];
        
        int l,c,M;
        c = 0;
        for(i=0;i!=n;i++)
            for(j=0;j!=m;j++)
                if(mat[i][j]) {
                    M = mat[i][j];
                    for(l=j;l!=m;l++)
                    {
                        M = min(M,mat[i][l]);
                        c += M;
                        
                        if(!M)
                            break;
                    }
                }
                
        return c;
    }
};
