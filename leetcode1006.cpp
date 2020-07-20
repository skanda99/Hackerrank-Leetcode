
// problem: "https://leetcode.com/problems/clumsy-factorial/"

class Solution {
public:
    int clumsy(int n) {
        
        int result = 0;
        bool p = 1;
        while(n>0)
        {
            if(n-3 >= 0)
            {
                if(p)
                {
                    result = result + n * (n-1) / (n-2) + (n-3);
                    p = !p;
                }
                else
                    result = result - n * (n-1) / (n-2) + (n-3);
                
                n = n-4;
            }
            else
            {
                if(p)
                    result += n;
                else
                    result -= n;
                
                n = 0;
            }
        }
        
        return result;
    }
};
