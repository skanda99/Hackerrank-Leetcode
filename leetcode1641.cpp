
// problem: "https://leetcode.com/problems/count-sorted-vowel-strings/"

class Solution {
public:
    int countVowelStrings(int n) {
        
        vector<vector<int>>V(n+1, vector<int>(5, 1));
        int i, j;
        for(i=2;i<=n;i++) {
            for(j=1;j!=5;j++) {
                V[i][j] = V[i][j-1]+V[i-1][j];
            }
        }
        
        int ans=0;
        for(j=0;j!=5;j++) {
            ans += V[n][j];
        }
        
        return ans;
    }
};
