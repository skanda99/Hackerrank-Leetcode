
// problem: "https://leetcode.com/problems/3sum/"

#define Pair pair<int,int>

class Solution {
public:
    int binSearch(vector<int>&A,int l,int r,int n)
    {
        if(l>r)
            return -1;

        int m = (l+r)/2;

        if(A[m] == n)
            return m;

        else if(A[m] < n)
            return binSearch(A,m+1,r,n);

        return binSearch(A,l,m-1,n);
    }

    vector<vector<int>> threeSum(vector<int>&A)
    {
        sort(A.begin(),A.end());
        set<Pair>S;
        int n = A.size();

        int i,j;

        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                if(binSearch(A,j+1,n-1,-A[i]-A[j]) != -1 && S.find(Pair(A[i],A[j])) == S.end())
                    S.insert(Pair(A[i],A[j]));
            }
        }

        vector<vector<int>>V;

        for(auto it=S.begin();it!=S.end();it++)
        {
            vector<int>t;
            Pair p = (*it);

            t.push_back(p.first);
            t.push_back(p.second);
            t.push_back(-p.first-p.second);

            V.push_back(t);
        }

        return V;
    }
};
