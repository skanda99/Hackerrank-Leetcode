
// problem: "https://leetcode.com/problems/evaluate-reverse-polish-notation/"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        int i,a,b;
        stack<string>S;
        
        for(i=0;i!=n;i++)
        {
            if(isOperator(tokens[i]))
            {
                b = stoi(S.top());
                S.pop();
                a = stoi(S.top());
                S.pop();
                
                S.push(eval(a,b,tokens[i]));
            }
            else
                S.push(tokens[i]);
        }
        
        return stoi(S.top());
    }
    
    bool isOperator(string token)
    {
        if(token == "+" || token == "-" || token == "*" || token == "/")
            return true;
        
        return false;
    }
    
    string eval(int a,int b,string token)
    {
        if(token == "+")
            return to_string(a+b);
        
        else if(token == "-")
            return to_string(a-b);
        
        else if(token == "*")
            return to_string(a*b);
        
        return to_string(a/b);
    }
};
