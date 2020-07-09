
// problem: "https://leetcode.com/problems/132-pattern/"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        if(nums.size() < 3)
            return false;
        
        int i,n;
        n = nums.size();
        vector<int>M(n);
        M[0] = nums[0];
        for(i=1;i!=n;i++)
            M[i] = min(M[i-1],nums[i-1]);
        
        stack<int>S;
        S.push(nums[n-1]);
        for(i=n-2;i>=0;i--)
        {
            if(M[i] < nums[i]-1)
            {
                while(!S.empty() && S.top() <= M[i])
                    S.pop();
                
                if(!S.empty() && S.top() < nums[i])
                    return true;                
            }
            
            S.push(nums[i]);
        }
        
        return false;
    }
};
