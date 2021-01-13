
// problem: "https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/"

class Solution {
public:
    unordered_map<int, int>M;
    
    int indexOf(int key) {
        if(M.count(key)) {
            return M[key];
        }
        
        return -1;
    }
    
    int lenLongestFibSubseq(vector<int>& arr) {
        int i, n, j, k, m;
        n = arr.size();
        
        for(i=0;i!=n;i++) {
            M[arr[i]] = i;
        }
        
        vector<vector<int>>dp(n ,vector<int>(n, 2));
        m = 0;
        for(i=1;i!=n;i++) {
            for(j=i+1;j!=n;j++) {
                k = indexOf(arr[j]-arr[i]);
                
                if(k >= i || k == -1) {
                    dp[i][j] = 2;
                }
                else {
                    dp[i][j] = 1 + dp[k][i];
                }
                
                m = max(m, dp[i][j]);
            }
        }
        
        if(m <= 2) {
            return 0;
        }
        
        return m;
    }
};
