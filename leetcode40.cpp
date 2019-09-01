
// problem: "https://leetcode.com/problems/combination-sum-ii/"

class Solution {
public:
    void allSeq(vector<int>B,int t,unordered_map<int,int>::iterator it,vector<vector<int>>&V,unordered_map<int,int>&M)
    {
        if(t==0)
            V.push_back(B);
        else if(t>0 && it!=M.end())
        {
            int i;
            for(i=0;i!=it->second+1;i++)
            {
                if(i==0)
                {
                    auto temp = it;
                    temp++;
                    allSeq(B,t,temp,V,M);
                }
                else
                {
                    auto temp = it;
                    temp++;
                    B.push_back(it->first);
                    t = t-it->first;
                    allSeq(B,t,temp,V,M);
                }
            }

        }
    }

    vector<vector<int>> combinationSum2(vector<int>&A, int target) {
        vector<vector<int>>V;
        vector<int>B;
        unordered_map<int,int>M;
        int i;
        for(i=0;i!=A.size();i++)
        {
            if(M.find(A[i]) != M.end())
                M[A[i]]++;
            else
                M[A[i]] = 1;
        }

        // for(auto it=M.begin();it!=M.end();it++)
        //     cout<<it->first<<' '<<it->second<<'\n';

        allSeq(B,target,M.begin(),V,M);

        return V;
    }
};
