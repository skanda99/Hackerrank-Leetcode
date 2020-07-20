
// problem: "https://leetcode.com/problems/smallest-range-ii/"

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        
        int n = A.size();
        sort(A.begin(),A.end());
        
        int i;
        for(i=0;i!=n;i++)
            A[i] += K;
        
        priority_queue<int>Q;
        int m = A[0],d = A[n-1]-A[0], M = n-1;
        for(i=n-1;i>0;i--)
        {
            A[i] -= 2*K;
            
            m = min(m,A[i]);
            Q.push(A[i]);
            
            d = min(d,max(A[i-1], Q.top())-m);
        }
        
        return d;
    }
    
    
};
