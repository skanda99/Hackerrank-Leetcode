
// problem: "https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/"

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i,c,s,n;
        s = 0;
        n = arr.size();
        c = 0;
        
        for(i=0;i!=k;i++) {
            s += arr[i];
        }
        
        if(s >= k*threshold) {
            c++;
        }
        
        i = k;
        while(i < n) {
            s += arr[i] - arr[i-k];
            
            if(s >= k*threshold) {
                c++;
            }
            
            i++;
        }
        
        return c;
    }
};
