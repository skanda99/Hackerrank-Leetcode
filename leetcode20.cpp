
// problem: "https://leetcode.com/problems/valid-parentheses/"

class Solution {
public:
    bool isValid(string s)
    {
        stack<char>S;
        int i;
        for(i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                S.push(s[i]);
            else if(s[i] == ')' && !S.empty() && S.top()=='(')
                S.pop();
            else if(s[i] == ']' && !S.empty() && S.top()=='[')
                S.pop();
            else if(s[i] == '}' && !S.empty() && S.top()=='{')
                S.pop();
            else
                return false;
        }

        if(S.empty())
            return true;

        return false;
    }
};
