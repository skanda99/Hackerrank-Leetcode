
// problem: "https://leetcode.com/problems/combination-sum/"

class Solution {
public:
    void allSeq(vector<int>V,int t,int i,vector<int>&A,vector<vector<int>>&ans)
    {
        if(t==0)
            ans.push_back(V);

        else if(!(t<0 || i>=A.size()))
        {
            allSeq(V,t,i+1,A,ans);
            //vector<int>B(V);
            V.push_back(A[i]);
            allSeq(V,t-A[i],i,A,ans);
        }
    }

    vector<vector<int>> combinationSum(vector<int>&A, int target) {
        vector<int>V;
        vector<vector<int>>ans;
        //vector<vector<bool>>M(target+1,vector<bool>(A.size(),false));
        allSeq(V,target,0,A,ans);
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};
