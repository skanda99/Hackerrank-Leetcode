
// problem: "https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/"

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.empty())
            return s;
        
        int n = s.size();
        vector<bool>V(n,false);
        stack<int>S;
        int i;
        for(i=0;i!=n;i++)
        {
            if(s[i] != ')' && s[i] != '(')
                V[i] = true;
            
            else if(s[i] == '(')
                S.push(i);
            
            else
            {
                if(!S.empty())
                {
                    V[i] = true;
                    V[S.top()] = true;
                    S.pop();
                }
            }
        }
        
        string ans = "";
        for(i=0;i!=n;i++)
            if(V[i])
              ans.append(string(1,s[i]));
        
        return ans;
    }
};
