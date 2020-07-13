
// problem: "https://leetcode.com/problems/super-ugly-number/"

#define ll long long

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        vector<ll>ugly;
        ugly.push_back(1);
        ll k = primes.size();
        vector<ll>V(k,0);
        
        ll p,i;
        p = 1;
        while(p < n)
        {
            ll m = 0;
            for(i=0;i!=k;i++)
                if(primes[i] * ugly[V[i]] < primes[m] * ugly[V[m]])
                    m = i;
            
            ll num = primes[m] * ugly[V[m]];
            V[m]++;
            
            if(num != ugly[p-1])
            {
                ugly.push_back(num);
                p++;
            }
        }
        
        return ugly[p-1];
    }
};
