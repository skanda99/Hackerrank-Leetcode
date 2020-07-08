
// problem: "https://leetcode.com/problems/132-pattern/"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        
        int i,n;
        n = nums.size();
        multiset<int>S;
        
        for(i=2;i!=n;i++)
            S.insert(nums[i]);
        
        int m = nums[0];
        for(i=1;i!=n-1;i++)
        {
            // cout<<m<<'\n';
            if(m <= nums[i]-2)
            {
                auto it = S.upper_bound(m);
                
                if(it != S.end())
                {   
                    int e = *it;

                    if(m < e && e < nums[i])
                    {
                        // cout<<m<<' '<<e<<' '<<nums[i];
                        return true;
                    }
                }
            }
            
            m = min(m,nums[i]);
            auto itr = S.find(nums[i+1]);
            if(itr != S.end())
                S.erase(itr);
        }
        
        return false;
    }
};
