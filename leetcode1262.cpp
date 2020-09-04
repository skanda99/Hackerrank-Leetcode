
// problem: "https://leetcode.com/problems/greatest-sum-divisible-by-three/"

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int i,s;
        s = 0;
        
        vector<int>G[3];
        for(i=0;i!=n;i++) {
            s += nums[i];
            
            if(nums[i]%3 == 1) {
                G[1].push_back(nums[i]);
            }
            else if(nums[i]%3 == 2) {
                G[2].push_back(nums[i]);
            }
        }
        
        sort(G[1].begin(), G[1].end());
        sort(G[2].begin(), G[2].end());
        
        if(s%3 == 1) {
            int c1,c2;
            c1 = c2 = INT_MAX;
            if(G[1].size() >= 1) {
                c1 = G[1][0];
            }
            
            if(G[2].size() >= 2) {
                c2 = G[2][0] + G[2][1];
            }
            
            return max(s-c1, s-c2);
        }
        else if(s%3 == 2) {
            
            int c1,c2;
            c1 = c2 = INT_MAX;
            if(G[2].size() >= 1) {
                c1 = G[2][0];
            }
            
            if(G[1].size() >= 2) {
                c2 = G[1][0] + G[1][1];
            }
            
            return max(s-c1, s-c2);
        }
        
        return s;
    }
};
