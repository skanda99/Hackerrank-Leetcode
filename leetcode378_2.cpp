
// problem: "https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int l,m,r,n,c,ans;
        n = matrix.size();
        l = matrix[0][0];
        r = matrix[n-1][n-1];
        
        while(l <= r) {
            m = (r-l)/2 + l;
            
            c = countLessThanM(matrix,m);
            
            if(c < k) {
                ans = m;
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        
        return ans;
    }
    
    int countLessThanM(vector<vector<int>>&M,int k) {
        
        int i,j,n,c;
        n = M.size();
        i = n-1;
        j = 0;
        
        c = 0;
        while(i >= 0 && j < n) {
            if(M[i][j] < k) {
                c += i+1;
                j++;
            }
            else
                i--;
        }
        
        return c;
    }
};
