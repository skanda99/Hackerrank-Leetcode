
// problem: "https://leetcode.com/problems/can-i-win/"

class Solution {
public:
    bool canIWin(int n, int t) {
        
        if(n*(n+1)/2 < t)
            return false;
        
        if(t <= 0)
            return true;
        
        vector<int>M(pow(2,n),-1);
        vector<bool>V(n+1,true);
        
        return canWin(t,V,1,M);
    }
    
    bool canWin(int t,vector<bool>&V,int i,vector<int>&M)
    {
        if(t <= 0)
        {
            if(i == 1)
                return false;
            
            else
                return true;
        }
        
        int m = getNum(V);
        
        if(M[m] != -1)
            return M[m];
        
        
        if(i == 1)
        {
            int n = V.size();
            int j;
            bool b = false;
            for(j=n-1;j>0;j--)
            {
                if(V[j])
                {
                    V[j] = false;
                    b = b || canWin(t-j,V,0,M);
                    V[j] = true;
                }
                
                if(b)
                    break;
                
            }
            
            M[m] = b;
        }
        else
        {
            int n = V.size();
            int j;
            bool b = true;
            for(j=n-1;j>0;j--)
            {
                if(V[j])
                {
                    V[j] = false;
                    b = b && canWin(t-j,V,1,M);
                    V[j] = true;
                }
                
                if(!b)
                    break;
            }
            
            M[m] = b;
        }
        
        return M[m];
    }
    
    int getNum(vector<bool>&V)
    {
        int i,n,p;
        n = 0;
        p = 1;
        for(i=1;i!=V.size();i++,p*=2)
            n += V[i]*p;
        
        return n;
    }
};
