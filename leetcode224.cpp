
// problem: "https://leetcode.com/problems/basic-calculator/"

class Solution {
public:
    int calculate(string s) {
        
        if(s.empty())
            return 0;
        
        stack<string>S;
        int a,b;
        string o;
        
        int i,n;
        s = "(" + s + ")";
        n = s.size();
        i = 0;
        while(i < n)
        {
            if(s[i] == ' ')
            {
                i++;
                continue;
            }
            
            if(s[i] == '(' || s[i] == '+' || s[i] == '-')
                S.push(string(1,s[i]));
            
            else if(s[i] != ')')
            {
                S.push(getNum(s,i));
                i += S.top().size();
                continue;
            }
            else
            {
                deque<string>Q;
                while(S.top() != "(")
                {
                    Q.push_front(S.top());
                    S.pop();
                }
                
                S.pop();
                
                a = stoi(Q.front());
                Q.pop_front();
                
                while(!Q.empty())
                {
                    
                    if(Q.front() == "+" || Q.front() == "-")
                        o = Q.front();
                    
                    else
                    {
                        b = stoi(Q.front());
                        
                        if(o == "+")
                            a = a+b;
                        else
                            a = a-b;
                    }
                    
                    Q.pop_front();
                }
                
                S.push(to_string(a));
            }
            
            i++;
        }
        
        return stoi(S.top());
    }
    
    string getNum(string &s,int i)
    {
        int j,n;
        n = s.size();
        for(j=i;j < n && isdigit(s[j]);j++);
        
        return s.substr(i,j-i);
    }
};
