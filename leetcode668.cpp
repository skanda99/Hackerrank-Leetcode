
// problem: "https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/"

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        int l,r,mid,c,ans;
        l = 1;
        r = m*n;
        
        while(l <= r) {
            mid = (r-l)/2 + l;
            
            c = countLessThanMid(m,n,mid);
            
            if(c < k) {
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        
        return ans;
    }
    
    int countLessThanMid(int &m,int &n,int &mid) {
        
        int i,c;
        c = 0;
        for(i=1;i<min(mid,m+1);i++) {
            
            if(mid%i) {
                c += min(mid/i, n);
            }
            else {
                c += min(mid/i-1, n);
            }
        }
        
        return c;
    }
};
