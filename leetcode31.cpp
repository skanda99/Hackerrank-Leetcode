
// problem: "https://leetcode.com/problems/next-permutation/"

class Solution {
public:
    void ReverSe(vector<int>&A,int i,int j)
    {
        while(i<j)
        {
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }

    void nextPermutation(vector<int>&A)
    {
        if(A.size()<2)
            return;

        int i,n;
        n = A.size();
        i = n-2;

        while(i>=0 && A[i]>=A[i+1])
            i--;

        ReverSe(A,i+1,n-1);     // define

        if(i >= 0)
        {
            int j = i+1;
            while(j<n && A[j]<=A[i])
                j++;

            swap(A[i],A[j]);
        }
    }
};
