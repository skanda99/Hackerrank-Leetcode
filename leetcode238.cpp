
// problem: "https://leetcode.com/problems/product-of-array-except-self/"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int>output(n,1);

        int i;
        for(i=n-2;i>=0;i--)
            output[i] = output[i+1]*nums[i+1];

        int p = 1;
        for(i=0;i!=n-1;i++)
        {
            output[i] = p*output[i];
            p *= nums[i];
        }

        output[n-1] = p;

        return output;
    }
};
