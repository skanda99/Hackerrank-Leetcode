
// problem: "https://leetcode.com/problems/reduce-array-size-to-the-half/"

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        vector<int>M(1e5+1,0);
        for(int x: arr) {
            M[x]++;
        }
        
        sort(M.begin(), M.end(), greater<int>());
        
        int i,s,n;
        s = 0;
        n = arr.size();
        for(i=0;s<(n+1)/2 && M[i]!=0;i++) {
            s += M[i];
        }
        
        return i;
    }
};
