
// problem: "https://leetcode.com/problems/first-missing-positive/"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        int i;
        for(i=0;i!=nums.size();i++)
        {
            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = 0;
        }

        n++;

        for(i=0;i!=nums.size();i++)
            nums[i] = nums[i] * n + i+1;

        for(i=0;i!=nums.size();i++)
            if(nums[i]/n != 0 && nums[nums[i]/n-1]%n != 0)
                nums[nums[i]/n-1] -= nums[nums[i]/n-1]%n;

        for(i=0;i!=nums.size();i++)
            if(nums[i]%n)
                break;

        return i+1;
    }
};
