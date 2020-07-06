
// problem: "https://leetcode.com/problems/wildcard-matching/"

class Solution {
public:
    bool isMatch(string &s, string &p) {
        
        int n,m;
        s = " " + s;
        p = " " + p;
        
        n = p.size();
        m = s.size();
        
        int i,j;
        vector<vector<bool>>V(n,vector<bool>(m,false));
        
        V[0][0] = true;
        
        for(i=1;i!=n;i++)
        {
            for(j=0;j!=m;j++)
            {
                if(p[i] == '*')
                {
                    if(i-1 >= 0 && V[i-1][j])
                        V[i][j] = true;
                    else if(i-1 >= 0 && j-1 >= 0 && V[i-1][j-1])
                        V[i][j] = true;
                    else if(j-1 >= 0 && V[i][j-1])
                        V[i][j] = true;
                }
                else
                {
                    if(i-1 >= 0 && j-1 >= 0 && V[i-1][j-1] && (p[i] == s[j] || p[i] == '?'))
                        V[i][j] = true;
                }
            }
        }
        
        return V[n-1][m-1];
    }
};
