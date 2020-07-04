
// problem: "https://leetcode.com/problems/jump-game/"

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int i,j,mj;
        i = j = mj = 0;
        while(i <= j && i < nums.size())
        {
            mj = max(mj,i+nums[i]);
            if(i == j)
                j = mj;

            i++;
        }

        if(i == nums.size())
            return true;

        return false;
    }
};
