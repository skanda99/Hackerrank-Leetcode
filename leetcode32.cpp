
// problem: "https://leetcode.com/problems/longest-valid-parentheses/"

class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int>S;
        vector<int>V(s.length(),0);

        int i,M;

        M = 0;
        for(i=0;i!=s.length();i++)
        {
            if(s[i] == '(')
                S.push(i);

            else if(s[i] == ')')
            {
                if(S.empty())
                    continue;

                int l = S.top();
                S.pop();

                if(l-1 >= 0)
                    V[i] = V[i]+V[l-1]+V[i-1]+2;

                else
                    V[i] = V[i]+V[i-1]+2;

                M = max(M,V[i]);
            }
        }

        return M;
    }
};
