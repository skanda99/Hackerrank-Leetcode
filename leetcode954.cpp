
// problem: "https://leetcode.com/problems/array-of-doubled-pairs/"

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int n(A.size());
        if(!n) {
            return true;
        }
        
        unordered_map<int, int>M;
        int i;
        for(i=0;i!=n;i++) {
            if(M.count(A[i])) {
                M[A[i]]++;
            }
            else {
                M[A[i]] = 1;
            }
        }
        
        sort(A.begin(), A.end());
        bool ans = true;
        
        int z = binSearch(A, 0);
        for(i=z;i!=n && ans;i++) {
            if(M[A[i]] > 0) {
                if(M.count(2*A[i]) && M[2*A[i]] > 0) {
                    M[2*A[i]]--;
                    M[A[i]]--;
                }
                else {
                    ans = false;
                }
            }
        }
        
        for(i=z-1;i>=0 && ans;i--) {
            if(M[A[i]] > 0) {
                if(M.count(2*A[i]) && M[2*A[i]] > 0) {
                    M[2*A[i]]--;
                    M[A[i]]--;
                }
                else {
                    ans = false;
                }
            }
        }
        
        return ans;
    }
    
    int binSearch(vector<int>&A, int key) {
        int l, r, m, ans;
        l = 0;
        r = A.size()-1;
        ans = A.size();
        while(l <= r) {
            m = (l+r)/2;
            if(A[m] < key) {
                l = m+1;
            }
            else {
                ans = min(ans, m);
                r = m-1;
            }
        }
        
        return ans;
    }
};
