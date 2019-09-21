
// problem: "https://leetcode.com/problems/search-in-rotated-sorted-array/"

class Solution {
public:
    int findT(int l,int r,vector<int>&A,int& T)
    {
        if(l>r)
            return -1;

        int m = (l+r)/2;

        if(T == A[m])
            return m;

        else if(T < A[m])
        {
            if(A[l] <= T)
                return findT(l,m-1,A,T);
            else
            {
                if(A[l] <= A[m])
                    return findT(m+1,r,A,T);
                else
                    return findT(l,m-1,A,T);
            }
        }
        else
        {
            if(T <= A[r])
                return findT(m+1,r,A,T);
            else
            {
                if(A[m] >= A[r])
                    return findT(m+1,r,A,T);
                else
                    return findT(l,m-1,A,T);
            }
        }
    }

    int search(vector<int>&A, int T)
    {
        return findT(0,A.size()-1,A,T);     // define
    }
};
