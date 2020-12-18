
// problem: "https://leetcode.com/problems/k-th-symbol-in-grammar/"

class Solution {
public:
    int kthGrammar(int N, int K) {
        return getKthSym(N-1, K-1);
    }
    
    bool getKthSym(int n, int k) {
        if(n == 0) {
            return false;
        }
        
        int p = getKthSym(n-1, k/2);
        
        if(p) {
            if(k%2) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            if(k%2) {
                return true;
            }
            else {
                return false;
            }
        }
        
        return false;
    }
};
