// problem: "https://leetcode.com/problems/maximum-product-subarray/"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l,r,m,Max,p;

        l = r = 0;
        p = 1;
        Max = m = nums[0];

        while(r < nums.size())
        {
            if(nums[r] == 0)
            {
                while(p<0 && l<r-1)
                {
                    p = p/nums[l];
                    m = max(m,p);
                    Max = max(Max,m);
                    l++;
                }

                Max = max(Max,0);
                while(r<nums.size() && nums[r]==0)
                    r++;

                l = r;
                p = 1;
            }
            else
            {
                p = p*nums[r];
                m = max(m,p);
                Max = max(Max,m);
                r++;
            }
        }

        while(p<0 && l<r-1)
        {
            p = p/nums[l];
            m = max(m,p);
            Max = max(Max,m);
            l++;
        }

        return Max;
    }
};
