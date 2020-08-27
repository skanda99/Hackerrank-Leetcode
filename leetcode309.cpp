
// problem: "https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.empty()) {
            return 0;
        }
        
        int i,s1,s2,S,n,N,b,B,r,R,m;
        
        m = prices.size();
        b = -prices[0];
        n = INT_MIN;
        s1 = s2 = INT_MIN;
        r = 0;
        
        for(i=1;i!=m;i++) {
            B = max(r, s2) - prices[i];
            N = max(b, n);
            S = max(b, n) + prices[i];
            R = max(s1, r);
            
            b = B;
            n = N;
            s2 = s1;
            s1 = S;
            r = R;
        }
        
        return max(b, max(s1, max(n, r)));
    }
};
