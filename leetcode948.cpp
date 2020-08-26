
// problem: "https://leetcode.com/problems/bag-of-tokens/"

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        
        int i,j,n,c;
        n = tokens.size();
        sort(tokens.begin(), tokens.end());
        
        i = 0;
        j = n-1;
        c = 0;
        while(i <= j) {
            if(tokens[i] <= P) {
                P -= tokens[i];
                i++;
                c++;
            }
            else {
                if(i != j && c > 0) {
                    P += tokens[j];
                    j--;
                    c--;
                }
                else {
                    break;
                }
            }
        }
        
        return c;
    }
};
