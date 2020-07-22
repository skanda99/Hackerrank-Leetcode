
// problem: "https://leetcode.com/problems/parsing-a-boolean-expression/"

class Solution {
public:
    bool parseBoolExpr(string s) {
        
        stack<char>S;
        int i,t,f,n;
        n = s.size();
        
        for(i=0;i!=n;i++) {
            if(s[i] != ',') {
                if(s[i] != ')') {
                    S.push(s[i]);
                }
                else {
                    t = f = 0;
                    while(S.top() != '(') {
                        if(S.top() == 't') {
                            t++;
                        }
                        else {
                            f++;
                        }
                        
                        S.pop();
                    }
                    
                    S.pop();
                    char o = S.top();
                    S.pop();
                    
                    if(o == '!') {
                        if(t) {
                            S.push('f');
                        }
                        else {
                            S.push('t');
                        }
                    }
                    else if(o == '&') {
                        if(f) {
                            S.push('f');
                        }
                        else {
                            S.push('t');
                        }
                    }
                    else {
                        if(t) {
                            S.push('t');
                        }
                        else {
                            S.push('f');
                        }
                    }
                }
            }
        }
        
        return S.top()-'f';
    }
};
