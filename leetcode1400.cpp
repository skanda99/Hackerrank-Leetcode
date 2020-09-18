
// problem: "https://leetcode.com/problems/construct-k-palindrome-strings/"

class Solution {
public:
    bool canConstruct(string s, int k) {
        
        int n = s.size();
        vector<int>Count(26,0);
        for(char c: s) {
            Count[c-'a']++;
        }
        
        int odd = 0;
        int i;
        for(i=0;i!=26;i++) {
            if(Count[i]%2) {
                odd++;
            }
        }
        
        if(odd <= k && k <= n) {
            return true;
        }
        
        return false;
    }   
};
