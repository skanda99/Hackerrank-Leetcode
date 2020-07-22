
// problem: "https://leetcode.com/problems/palindromic-substrings/"

class Solution {
public:
    int countSubstrings(string s) {
        
        int i,j,k,n,c;
        n = s.size();
        
        c = 0;
        for(k=0;k!=n;k++) {
            i = k;
            j = k;
            
            while(i >= 0 && j < n) {
                if(s[i] == s[j]) {
                    c++;    
                }
                else {
                    break;
                }
                
                i--;
                j++;
            }
        }
        
        for(k=0;k!=n-1;k++) {
            if(s[k] == s[k+1]) {
                i = k;
                j = k+1;
                
                while(i >= 0 && j < n) {
                    if(s[i] == s[j]) {
                        c++;
                    }
                    else {
                        break;
                    }
                    
                    i--;
                    j++;
                }
            }
        }
        
        return c;
    }
};
