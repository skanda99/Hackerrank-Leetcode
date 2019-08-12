
// problem: "https://leetcode.com/problems/two-sum/"

class Solution {
public:

    int binaryS(vector<int>&A,int k,int l,int r)
    {
        if(l>r)
            return -1;

        int m = (l+r)/2;

        if(A[m] == k)
            return A[m];
        else if(A[m]>k)
        {
            //r = m-1;
            return binaryS(A,k,l,m-1);
        }
        else
            return binaryS(A,k,m+1,r);
    }

    int indexOf(vector<int>&nums,int k,int j)
    {
        int i;
        for(i=0;i!=nums.size();i++)
            if(i!=j && nums[i]==k)
                return i;

        return -1;
    }


    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>nums_c(nums);

        sort(nums_c.begin(),nums_c.end());
        vector<int>sol(2);
        int i;
        for(i=0;i!=nums_c.size();i++)
        {
            int x = binaryS(nums_c,target-nums_c[i],0,nums.size()-1);       // define

            if(x+nums_c[i] == target)
            {

                sol[0] = indexOf(nums,nums_c[i],-1);        // define
                sol[1] = indexOf(nums,x,sol[0]);

                break;
            }
        }

        return sol;
    }
};
