
// problem: "https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/"

#define ll long long
#define p (ll)(1e9+7)

class Solution {
public:
    int countOrders(ll n) {
        if(n == 1)
            return 1;
        
        return (countOrders(n-1)*(n*(2*n-1)))%p;
    }
};
