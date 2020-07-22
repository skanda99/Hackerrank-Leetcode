
// problem: "https://leetcode.com/problems/longest-common-subsequence/"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n,m;
        n = text1.size();
        m = text2.size();
        
        vector<vector<int>>V(n+1,vector<int>(m+1,0));
        
        int i,j;
        for(i=1;i!=n+1;i++) {
            for(j=1;j!=m+1;j++) {
                if(text1[i-1] == text2[j-1]) {
                    V[i][j] = V[i-1][j-1]+1;
                }
                else {
                    V[i][j] = max(V[i-1][j], V[i][j-1]);
                }
            }
        }
        
        return V[n][m];
    }
};
