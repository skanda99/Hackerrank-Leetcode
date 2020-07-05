
// problem: "https://leetcode.com/problems/maximum-width-ramp/"

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        if(A.empty())
            return 0;

        stack<int>S;
        int i,m;
        m = 0;
        for(i=0;i!=A.size();i++)
        {
            if(S.empty() || A[S.top()] > A[i])
                S.push(i);

            if(A[S.top()] <= A[i])
                m = i;
        }

        i = m;
        m = 0;
        while(!S.empty())
        {
            m = max(m,i-S.top());
            S.pop();

            if(!S.empty())
            {
                while(i >= 0 && A[i] < A[S.top()])
                    i--;
            }
        }

        return m;
    }
};
