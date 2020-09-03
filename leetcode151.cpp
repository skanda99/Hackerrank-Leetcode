
// problem: "https://leetcode.com/problems/reverse-words-in-a-string/"

class Solution {
public:
    
    void reverseIJ(string &s, int i, int j) {

        while(i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    
    string reverseWords(string s) {
        
        int i,j,n;
        n = s.size();
        
        reverseIJ(s, 0, n-1);
        
        int k;
        k = 0;
        while(k < n) {
            if(s[k] == ' ') {
                k++;
            }
            else {
                i = k;
                j = k;
                while(j < n && s[j] != ' ') {
                    j++;
                }
                j--;
                
                reverseIJ(s, i, j);
                
                k = j+1;
            }
        }
        
        i = 0;
        j = 0;
        
        while(j < n) {
            if(s[j] != ' ') {
                
                if(j > 0 && s[j-1] == ' ' && i != 0) {
                    s[i] = ' ';
                    i++;
                }
                
                s[i] = s[j];
                i++;
            }
            
            j++;
        }
        
        return s.substr(0, i);
    }
};
