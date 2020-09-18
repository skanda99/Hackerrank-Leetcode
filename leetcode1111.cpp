
// problem: "https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/"

class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        stack<bool>S;
        int n = s.size();
        vector<int>V(n);
        int i;
        
        for(i=0;i!=n;i++) {
            if(s[i] == '(') {
                if(S.empty()) {
                    S.push(0);
                    V[i] = 0;
                }
                else {
                    S.push(!S.top());
                    V[i] = S.top();
                }
            }
            else {
                V[i] = S.top();
                S.pop();
            }
        }
        
        return V;
    }
};
