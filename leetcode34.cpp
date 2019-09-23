
// problem: "https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/"

class Solution {
public:

    int leftSearch(int l,int r,vector<int>&A,int T)
    {
        if(l>r)
            return INT_MAX;

        int m = (l+r)/2;

        if(A[m] == T)
            return min(m,leftSearch(l,m-1,A,T));

        else if(A[m] < T)
            return leftSearch(m+1,r,A,T);

        return leftSearch(l,m-1,A,T);
    }

    int rightSearch(int l,int r,vector<int>&A,int T)
    {
        if(l>r)
            return INT_MIN;

        int m = (l+r)/2;

        if(A[m] == T)
            return max(m,rightSearch(m+1,r,A,T));

        else if(A[m] < T)
            return rightSearch(m+1,r,A,T);

        return rightSearch(l,m-1,A,T);
    }

    vector<int> searchRange(vector<int>&A, int T)
    {
        vector<int>V = {-1,-1};
        if(A.empty())
            return V;

        int l = leftSearch(0,A.size()-1,A,T);       // define
        int r = rightSearch(0,A.size()-1,A,T);      // define

        if(l != INT_MAX)
            V[0] = l;

        if(r != INT_MIN)
            V[1] = r;

        return V;
    }
};
