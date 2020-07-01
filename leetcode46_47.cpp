
// problem: "https://leetcode.com/problems/permutations/"
// problem: "https://leetcode.com/problems/permutations-ii/"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>S;
        if(nums.empty())
            return S;

        unordered_map<int,int>C;
        for(int i: nums)
        {
            if(C.count(i))
                C[i]++;

            else
                C[i] = 1;
        }

        dfs(0,nums.size(),vector<int>(),C,S);           // define

        return S;
    }

    void dfs(int c,int n,vector<int>V,unordered_map<int,int>C,vector<vector<int>>&S)
    {
        if(c == n)
        {
            S.push_back(V);
            return;
        }

        for(auto it=C.begin();it!=C.end();it++)
        {
            if(it->second > 0)
            {
                it->second--;
                V.push_back(it->first);

                dfs(c+1,n,V,C,S);

                it->second++;
                V.erase(V.end()-1);
            }
        }
    }
};
