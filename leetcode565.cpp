
// problem: "https://leetcode.com/problems/array-nesting/"

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int i, n, m;
        n = nums.size();
        vector<int>V(n, -1);
        m = 0;
        
        for(i=0;i!=n;i++) {
            if(V[i] == -1) {
                V[i] = 0;
                V[i] = maxLength(nums, V, nums[i], 1);
            }
            m = max(m, V[i]);
        }
        
        // test
        // for(i=0;i!=n;i++) {
        //     cout<<V[i]<<' ';
        // }
        
        return m;
    }
    
    int maxLength(vector<int>&nums, vector<int>&V, int i, int l) {
        if(V[i] == 0) {
            return l;
        }
        
        V[i] = 0;
        V[i] = maxLength(nums, V, nums[i], l+1);
        return V[i];
    }
}; 
