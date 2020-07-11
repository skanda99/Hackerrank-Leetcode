
// problem: "https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/"

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        vector<int>V(2*k-1,0);
        int i,n;
        n = arr.size();
        for(i=0;i!=n;i++)
            V[arr[i]%k + k-1]++;
        
        for(i=0;i!=2*k-1;i++)
        {
            int a = i-k+1;
            
            int b = -a;
            
            if(b == a && V[i]%2)
                return false;
            else if(b == a)
                continue;
            
            int c = (a > 0)?k-a:-k-a;
            
            if(a == c && (V[a+k-1]+V[b+k-1])%2)
                return false;
            else
            {
                if(V[a+k-1] > V[b+k-1]+V[c+k-1])
                    return false;
            }
        }
        
        return true;
    }
};
