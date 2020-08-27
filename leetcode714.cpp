
// problem: "https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int B,N,S,R,b,n,s,r,i,m;
        m = prices.size();
        b = -prices[0]-fee;
        n = INT_MIN;
        s = INT_MIN;
        r = 0;
        
        for(i=1;i!=m;i++) {
            B = max(r, s) - prices[i] - fee;
            N = max(b, n);
            S = max(b, n) + prices[i];
            R = max(s, r);
            
            b = B;
            n = N;
            s = S;
            r = R;
        }
        
        return max(b, max(n, max(s, r)));
    }
};
