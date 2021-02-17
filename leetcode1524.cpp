
// problem: "https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/"

#define ll long long
#define p (ll)(1e9+7)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        int i;
        for(i=1;i!=arr.size();i++) {
            arr[i] = arr[i-1] + arr[i];
        }
        
        ll o, e, ans;
        o = e = ans = 0;
        for(i=0;i!=arr.size();i++) {
            if(arr[i] % 2) {
                ans = (ans + (1 + e)%p)%p;
                o = (o+1)%p;
            }
            else {
                ans = (ans + o)%p;
                e = (e+1)%p;
            }
        }
        
        return ans;
    }
};
