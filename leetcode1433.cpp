
// problem: "https://leetcode.com/problems/check-if-a-string-can-break-another-string/"

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        int i,n;
        n = s1.size();
        bool f;
        f = true;
        for(i=0;i!=n;i++) {
            if(s2[i] < s1[i]) {
                f = false;
            }
        }
        
        if(f) {
            return f;
        }
        
        f = true;
        for(i=0;i!=n;i++) {
            if(s1[i] < s2[i]) {
                f = false;
            }
        }
        
        return f;
    }
};
