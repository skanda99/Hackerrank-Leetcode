
// problem: "https://leetcode.com/problems/container-with-most-water/"

class Solution {
public:

    int maxArea(int l,int r,vector<int>&A)
    {
        if(l>=r)
            return 0;

        if(A[l]<A[r])
            return max(A[l]*(r-l),maxArea(l+1,r,A));

        else if(A[l]>A[r])
            return max(A[r]*(r-l),maxArea(l,r-1,A));

        else if(A[l+1]>A[r-1])
            return max(A[l]*(r-l),maxArea(l+1,r,A));
        else
            return max(A[l]*(r-l),maxArea(l,r-1,A));
    }

    int maxArea(vector<int>& height) {

        return maxArea(0,height.size()-1,height);
    }
};
