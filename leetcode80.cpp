
// problem: "https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 2) {
            return n;
        }
        
        int i,j;
        i = 1;
        for(j=2;j!=n;j++) {
            if(!(nums[j] == nums[i] && nums[j] == nums[i-1])) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i+1;
    }
};
