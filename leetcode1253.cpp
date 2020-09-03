
// problem: "https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/"

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        
        int n = colsum.size(), u, l;
        u = upper;
        l = lower;
        vector<vector<int>>V(2, vector<int>(n,0));
        
        int i,c;
        c = 0;
        for(i=0;i!=n;i++) {
            if(colsum[i] == 2) {
                V[1][i] = V[0][i] = 1;
                
                upper--;
                lower--;
                c++;
            }
            else if(colsum[i] == 0) {
                V[1][i] = V[0][i] = 0;
            }
            else {
                V[0][i] = 1;
                upper--;
                c++;
            }
        }
        
        if(upper + lower != 0 || c < u || c < l) {
            return vector<vector<int>>();
        }
        
        for(i=0;i!=n && upper < 0;i++) {
            if(V[0][i] == 1 && V[1][i] == 0) {
                V[0][i] = 0;
                V[1][i] = 1;
                upper++;
            }
        }
        
        return V;
    }
};
