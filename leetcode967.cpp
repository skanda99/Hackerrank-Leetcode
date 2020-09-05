
// problem: "https://leetcode.com/problems/numbers-with-same-consecutive-differences/"

class Solution {
public:
    void getNums(int d, vector<int>&v, int i, int l, int k, vector<vector<int>>&V) {
        if(i == l) {
            V.push_back(v);
            return;
        }
        
        if(d-k >= 0) {
            v[i] = d-k;
            getNums(v[i], v, i+1, l, k, V);
        }
        
        if(d+k <= 9 && d+k != d-k) {
            v[i] = d+k;
            getNums(v[i], v, i+1, l, k, V);
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        
        vector<vector<int>>V;
        
        if(N == 1) {
            V.push_back(vector<int>(1, 0));
        }
        
        int i;
        vector<int>v(N);
        
        for(i=1;i!=10;i++) {    
            v[0] = i;
            getNums(i,v,1,N,K,V);       // define
        }
        
        int j,n;
        vector<int>ans;
        for(i=0;i!=V.size();i++) {
            n = 0;
            for(j=0;j!=N;j++) {
                n = n*10 + V[i][j];
            }
            
            ans.push_back(n);
        }
        
        return ans;
    }
};
