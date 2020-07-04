
// problem: "https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/"

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(0,nums.size()-1,nums[0],nums);       // define
    }

    int findMin(int i,int j,int n,vector<int>&V)
    {
        if(i > j)
            return INT_MAX;

        int m = (i+j)/2;

        if(V[m] < n)
            return min(V[m],findMin(i,m-1,n,V));

        return min(n,findMin(m+1,j,n,V));
    }
};
