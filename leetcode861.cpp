
// problem: "https://leetcode.com/problems/score-after-flipping-matrix/"

class Solution {
public:
    
    void toggleRow(vector<vector<int>>&A, int i) {
        int j,m;
        m = A[0].size();
        for(j=0;j!=m;j++) {
            A[i][j] = !A[i][j];
        }
    }
    
    int matrixScore(vector<vector<int>>& A) {
        int n,m,i,j;
        n = A.size();
        m = A[0].size();
        
        for(i=0;i!=n;i++) {
            if(!A[i][0]) {
                toggleRow(A,i);
            }
        }
        
        int c,num;
        num = 0;
        for(j=0;j!=m;j++) {
            c = 0;
            for(i=0;i!=n;i++) {
                if(A[i][j]) {
                    c++;
                }
            }
            
            num += max(c*pow(2,m-1-j), (n-c)*pow(2,m-1-j));
        }
        
        return num;
    }
};
