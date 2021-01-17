
// problem: "https://leetcode.com/problems/sliding-window-maximum/"

class Solution {
public:
    
    void insertDQ(vector<int>&nums, deque<int>&dq, int i) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int i, n;
        n = nums.size();
        
        for(i=0;i!=k;i++) {
            insertDQ(nums, dq, i);
        }
        
        vector<int>ans;
        ans.push_back(nums[dq.front()]);
        
        for(i=k;i!=n;i++) {
            insertDQ(nums, dq, i);
            
            while(dq.back() - dq.front() + 1 > k) {
                dq.pop_front();
            }
            
            ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};
