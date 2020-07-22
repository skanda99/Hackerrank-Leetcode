
// problem: "https://leetcode.com/problems/longest-palindromic-subsequence/"


class Solution {
public:
    int longestPalindromeSubseq(string text) {
        
        int n;
        n = text.size();
        
        vector<vector<int>>V(n+1,vector<int>(n+1,0));
        
        int i,j;
        for(i=1;i!=n+1;i++) {
            for(j=1;j!=n+1;j++) {
                if(text[i-1] == text[n-j]) {
                    V[i][j] = V[i-1][j-1]+1;
                }
                else {
                    V[i][j] = max(V[i-1][j], V[i][j-1]);
                }
            }
        }
        
        return V[n][n];
    }
};
