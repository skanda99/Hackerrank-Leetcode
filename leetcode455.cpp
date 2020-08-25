
// problem: "https://leetcode.com/problems/assign-cookies/"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        
        int i,j,n,m;
        n = s.size();
        m = g.size();
        
        i = j = 0;
        while(i < n && j < m) {
            
            while(j < m && g[j] > s[i]) {
                j++;
            }
            
            if(j < m) {
                i++;
                j++;
            }
        }
        
        return i;
    }
};
