
// problem: "https://leetcode.com/problems/ugly-number-ii/"

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        
        int i,j,k,p,m;
        vector<int>V(n);
        
        V[0] = 1;
        p = 1;
        i = j = k = 0;
        
        while(p<n)
        {
            m = 2*V[i];
            m = min(m,3*V[j]);
            m = min(m,5*V[k]);
            
            
            
            if(m==2*V[i])
                i++;   
            else if(m==3*V[j])
                j++;
            else
                k++;
            
            if(m==V[p-1])
                continue;
            
            V[p] = m;
            p++;
        }
        
        // for(i=0;i!=n;i++)
        //     cout<<V[i]<<' ';
        
        return V[n-1];
    }
};
