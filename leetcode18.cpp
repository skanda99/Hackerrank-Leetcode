
//  problem: "https://leetcode.com/problems/4sum/"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>&A, int T)
    {
        sort(A.begin(),A.end());
        vector<vector<int>>V;
        int n = A.size();

        if(n<=3)
            return V;

        int i,j,k;
        unordered_set<int>S;
        for(i=0;i<n;i++)
            S.insert(A[i]);


        i = 0;
        while(i<n-3)
        {
            j = i+1;
            while(j<n-2)
            {
                k = j+1;
                while(k<n-1)
                {
                    int r = T-A[i]-A[j]-A[k];

                    if(r > A[k] && S.find(r) != S.end())
                    {
                        vector<int>t = {A[i],A[j],A[k],r};
                        V.push_back(t);
                    }
                    else if(r == A[k] && r == A[k+1])
                    {
                        vector<int>t = {A[i],A[j],A[k],r};
                        V.push_back(t);
                    }

                    k++;
                    while(k<n-1 && A[k]==A[k-1])
                        k++;
                }

                j++;
                while(j<n-2 && A[j]==A[j-1])
                    j++;
            }

            i++;
            while(i<n-3 && A[i]==A[i-1])
                i++;
        }

        return V;
    }
};
