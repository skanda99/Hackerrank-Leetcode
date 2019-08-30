
// problem: "https://leetcode.com/problems/divide-two-integers/"

#define ll long long

class Solution {
public:

    ll Div(ll a,ll b)
    {
        if(a<b)
            return 0;

        ll c = b,d=1;
        while(a>=c)
        {
            c = c<<1;
            d = d<<1;
        }

        c = c>>1;
        d = d>>1;

        return Div(a-c,b)+d;
    }

    int divide(int dividend, int divisor) {
        int p = 1;

        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            p = -1;

        ll a,b;
        a = dividend;
        b = divisor;

        ll ans = Div(abs(a),abs(b));       // define
        ans = ans*p;

        if(ans > INT_MAX)
            ans = INT_MAX;

        return ans;
    }
};
