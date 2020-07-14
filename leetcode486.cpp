
// problem: "https://leetcode.com/problems/predict-the-winner/"

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        return can1Win(nums,0,nums.size()-1,0,0,1);
    }
    
    bool can1Win(vector<int>&nums,int i,int j,int score1,int score2,int p)
    {
        if(i > j)
        {
            if(score1 >= score2)
                return true;
            
            else
                return false;
        }
        
        if(p == 1)
            return can1Win(nums,i+1,j,score1+nums[i],score2,0) || can1Win(nums,i,j-1,score1+nums[j],score2,0);
        
        return can1Win(nums,i+1,j,score1,score2+nums[i],1) && can1Win(nums,i,j-1,score1,score2+nums[j],1);
    }
};
