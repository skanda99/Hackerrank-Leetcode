
// problem: "https://leetcode.com/problems/can-convert-string-in-k-moves/"

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) {
            return false;
        }
        
        int i,n;
        n = s.size();
        vector<int>V(26,0);
        
        for(i=0;i!=n;i++) {
            V[(t[i]-s[i]+26)%26]++;
        }
        
        int m = 0;
        for(i=1;i!=26;i++) {
            m = max(m, i + (V[i]-1) * 26);
        }
        
        if(m > k) {
            return false;
        }
        
        return true;
    }
};
