
// problem: "https://leetcode.com/problems/4sum-ii/"


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        vector<int>X;
        unordered_map<int, int>Y;
        int i, j, n;
        n = A.size();
        for(i=0;i!=n;i++) {
            for(j=0;j!=n;j++) {
                X.push_back(A[i]+B[j]);
                
                if(Y.count(C[i]+D[j])) {
                    Y[C[i]+D[j]]++;
                }
                else {
                    Y[C[i]+D[j]] = 1;
                }
            }
        }
        
        int count = 0;
        for(i=0;i!=n*n;i++) {
            if(Y.count(-X[i])) {
                count += Y[-X[i]];
            }
        }
        
        return count;
    }
};
