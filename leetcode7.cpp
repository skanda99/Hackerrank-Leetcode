
// problem: "https://leetcode.com/problems/reverse-integer/"

class Solution {
public:
    int reverse(int x) {
        bool n = 0;

        long long int p = x;
        if(x<0)
        {
            n = 1;
            p = -p;
        }

        long long int r = 0;

        while(p)
        {
            r = r*10 + p%10;
            p /= 10;
        }

        if(n == 0 && r>2147483647)
            return 0;

        if(n == 1 && r>2147483648)
            return 0;

        if(n == 1)
            r = -r;

        return r;
    }
};
