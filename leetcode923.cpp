
// problem: "https://leetcode.com/problems/3sum-with-multiplicity/"

#define p (int)(1e9+7)

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        
        int i,j,k,n,c;
        n = A.size();
        c = 0;
        for(i=0;i!=n;i++) {
            vector<int>V(301,0);
            for(j=n-1;j>i;j--) {
                if(target-A[i]-A[j] >= 0) {
                    c = (c+V[target-A[i]-A[j]])%p;
                }
                
                V[A[j]]++;
            }
        }
        
        return c;
    }
};
