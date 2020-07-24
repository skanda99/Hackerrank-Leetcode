
// problem: "https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/"

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        
        queue<vector<vector<int>>>Q;
        Q.push(mat);
        
        int m,n,i,j;
        m = mat.size();
        n = mat[0].size();
        
        vector<int>V(pow(2,m*n),-1);
        V[equivalent(mat,m,n)] = 0;
        
        while(!Q.empty()) {
            vector<vector<int>>p = Q.front();
            int val = equivalent(p,m,n);
            Q.pop();
            
            for(i=0;i!=m;i++) {
                for(j=0;j!=n;j++) {
                    vector<vector<int>>v = p;
                    
                    v[i][j] = !v[i][j];
                    
                    if(i-1 >= 0) {
                        v[i-1][j] = !v[i-1][j];
                    }
                    
                    if(i+1 < m) {
                        v[i+1][j] = !v[i+1][j];
                    }
                    
                    if(j-1 >= 0) {
                        v[i][j-1] = !v[i][j-1];
                    }
                    
                    if(j+1 < n) {
                        v[i][j+1] = !v[i][j+1];
                    }
                    
                    int k = equivalent(v,m,n);
                    if(V[k] == -1) {
                        V[k] = V[val]+1;
                        Q.push(v);
                    }
                }
            }
        }
        
        return V[0];
    }
    
    int equivalent(vector<vector<int>>&M,int &m,int &n) {
        int i,j,p,ans;
        ans = 0;
        p = 1;
        for(i=0;i!=m;i++) {
            for(j=0;j!=n;j++) {
                ans += M[i][j] * p;
                p *= 2;
            }
        }
        
        return ans;
    }
    
};
