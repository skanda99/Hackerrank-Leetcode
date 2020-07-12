
// problem: "https://leetcode.com/problems/basic-calculator-ii/"

class Solution {
public:
    int calculate(string s) {
        
        int i,n,a,b;
        n = s.size();
        stack<int>nums;
        stack<string>operators;
        
        i = 0;
        while(i < n)
        {
            if(s[i] == ' ')
            {
                i++;
                continue;
            }
            
            if(isOperator(s[i]))
            {
                while(!checkPrecedence(s[i],operators))
                {
                    b = nums.top();
                    nums.pop();
                    
                    a = nums.top();
                    nums.pop();
                    
                    nums.push(eval(a,b,operators.top()));
                    operators.pop();
                }
                
                operators.push(string(1,s[i]));
                i++;
            }
            else
                nums.push(getNum(s,i));
        }
        
        while(!operators.empty())
        {
            b = nums.top();
            nums.pop();
            
            a = nums.top();
            nums.pop();
            
            nums.push(eval(a,b,operators.top()));
            
            operators.pop();
        }
        
        return nums.top();
    }
    
    bool checkPrecedence(char o,stack<string>&operators)
    {
        if(operators.empty())
            return true;
        
        if(o == '+' || o == '-')
            return false;
        
        if(o == '/' && (operators.top() == "/" || operators.top() == "*"))
            return false;
        
        if(o == '*' && (operators.top() == "/" || operators.top() == "*"))
            return false;
        
        return true;
    }
    
    bool isOperator(char c)
    {
        if(c == '+' || c == '-' || c == '/' || c == '*')
            return true;
        
        return false;
    }
    
    int getNum(string &s,int &i)
    {
        int j,n;
        n = s.size();
        for(j=i;j<n && isdigit(s[j]);j++);
        
        int i_copy = i;
        i = j;
        return stoi(s.substr(i_copy,j-i_copy));
    }
    
    int eval(int a,int b,string token)
    {
        if(token == "+")
            return a+b;
        
        else if(token == "-")
            return a-b;
        
        else if(token == "*")
            return a*b;
        
        return a/b;
    }
};
