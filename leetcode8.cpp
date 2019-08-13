
// problem: "https://leetcode.com/problems/string-to-integer-atoi/"

class Solution {
public:
    int myAtoi(string str)
    {
        long long ans,i,sign=0;
        ans = 0;
        for(i=0;i!=str.size();i++)
        {
            if(str[i]=='+' && sign==0)
                sign = 1;
            else if(str[i]=='-' && sign==0)
                sign = -1;
            else if(str[i]==' ' && sign==0)
                continue;
            else if(str[i]>='0' && str[i]<='9')
            {
                int j=i;
                while(j<str.size() && str[j]>='0' && str[j]<='9')
                {
                    ans = ans*10+(long long)(str[j]-'0');
                    if(ans>2147483649)
                    {
                        break;
                    }
                    j++;
                }
                if(sign==0)
                    sign=1;
                break;
            }
            else
                break;
        }

        if(sign==-1)
        {
            ans = -ans;
            if(ans<INT_MIN)
                ans = INT_MIN;
        }
        else
        {
            if(ans>INT_MAX)
                ans = INT_MAX;
        }

        return ans;
    }
};
