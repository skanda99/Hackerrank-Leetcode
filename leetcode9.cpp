
// problem: "https://leetcode.com/problems/palindrome-number/"

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;

        if(x==0)
            return true;

        if(!(x%10))
            return false;

        long int y,n;
        y = 0;
        n = x;

        while(n)
        {
            y = y*10+n%10;
            n /= 10;
        }

        if(y == x)
            return true;

        return false;
    }
};
