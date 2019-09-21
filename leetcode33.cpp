
// problem: "https://leetcode.com/problems/search-in-rotated-sorted-array/"

class Solution {
public:

    int binarySearch(vector<int>&A,int l,int r,int T)
    {
        if(l>r)
            return -1;

        int m = (l+r)/2;

        if(A[m] == T)
            return m;

        if(A[m] < T)
            return binarySearch(A,m+1,r,T);

        return binarySearch(A,l,m-1,T);
    }

    int pivot(int l,int r,vector<int>&A)
    {
        if(l == r-1 || l == r)
            return l;

        int m = (l+r)/2;

        if(A[l] < A[m])
            return pivot(m,r,A);

        return pivot(l,m,A);
    }

    int search(vector<int>&A, int T)
    {
        if(A.empty())
            return -1;

        int p = pivot(0,A.size()-1,A);      // define

        if(A[p] == T)
            return p;

        int L = binarySearch(A,0,p-1,T);        // define

        if(L != -1)
            return L;

        int R = binarySearch(A,p+1,A.size()-1,T);

        return R;
    }
};
