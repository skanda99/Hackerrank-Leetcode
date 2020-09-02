
// problem: "https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/"

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int i,j,l,r,n,c;
        n = A.size();
        
        for(i=1;i!=7;i++) {
            l = r = c = 0;
            for(j=0;j!=n;j++) {
                if(A[j] == i && B[j] == i) {
                    c++;
                }
                
                if(A[j] == i) {
                    l++;
                }
                
                if(B[j] == i) {
                    r++;
                }
            }
            
            if(l+r-c == n) {
                return min(l-c, r-c);
            }
        }
        
        return -1;
    }
};
