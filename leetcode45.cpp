
// problem: "https://leetcode.com/problems/jump-game-ii/"

class Solution {
public:
    int jump(vector<int>& nums) {

        int i,j,mi,s;
        j = s = mi = 0;

        for(i=0;i!=nums.size();i++)
        {
            if(i == nums.size()-1)
                return s;

            mi = max(mi,i+nums[i]);
            if(i == j)
            {
                s++;
                j = mi;
            }
        }

        return 0;
    }
};
