
// problem: "https://leetcode.com/problems/2-keys-keyboard/"


vector<int>V(1001,-1);

class Solution {
public:
    
    int minSteps(int n) {
        
        if(n == 1)
            return 0;
        
        if(V[n] == -1)
        {
            int m = INT_MAX;

            int i;
            for(i=1;i<=n/2;i++)
                if(n%i == 0)
                    m = min(m,minSteps(i)+n/i);

            V[n] =  m;
        }
        
        return V[n];
    }
};
