
// problem: "https://leetcode.com/problems/3sum-closest/"

class Solution {
public:
    int threeSumClosest(vector<int>&A, int T)
    {
        int n = A.size();
        sort(A.begin(),A.end());

        int i,j,k;
        int a,p;
        a = INT_MAX;

        i = 0;
        while(i<n)
        {
            j = i+1;
            k = n-1;

            while(j<k)
            {
                int s = A[i]+A[j]+A[k];

                if(a > abs(T-s))
                {
                    a = abs(T-s);
                    p = s;
                }

                if(s > T)
                    k--;
                else if(s < T)
                    j++;
                else
                    break;
            }

            i++;
        }

        return p;
    }
};
