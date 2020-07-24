
// problem: "https://leetcode.com/problems/pancake-sorting/"

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int i,j,n;
        n = A.size();
        vector<int>V;
        for(i=n-1;i>0;i--) {
            if(A[i] != i+1) {
                j = locate(A,i+1);
                
                reverse(A.begin(), A.begin()+j+1);
                V.push_back(j+1);
                
                reverse(A.begin(), A.begin()+i+1);
                V.push_back(i+1);
            }
        }
        
        return V;
    }
    
    int locate(vector<int>&A, int n) {
        int i;
        for(i=0;i!=A.size();i++) {
            if(A[i] == n) {
                return i;
            }
        }
        
        return -1;
    }
};
