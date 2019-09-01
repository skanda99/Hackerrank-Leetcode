
// problem: "https://leetcode.com/problems/powx-n/"

class Solution {
public:
    double aPn(double a,long int n)
    {
        if(n==0)
            return 1;

        double b,ans;
        b=1.0;

        if(n%2)
            b=a;

        a=aPn(a,n/2);
        ans=a*a*b;

        return ans;
    }

    double myPow(double x, long int n) {
        if(x==0.0 && n!=0)
            return 0;

        if(n>=0)
            return aPn(x,n);


        return 1/aPn(x,-n);
    }
};
