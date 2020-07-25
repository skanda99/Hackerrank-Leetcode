
// problem: "https://leetcode.com/problems/k-th-smallest-prime-fraction/"

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        
        int i,j,c;
        
        float a,b,m;
        a = 0;
        b = 1;
        
        while(b-a > 1e-7) {
            m = (a+b)/2.0;
            // cout<<a<<' '<<b<<' '<<m<<'\n';
                
            c = countLess(m,A);
            
            if(c < K) {
                a = m;
            }
            else {
                b = m;
            }
        }
        
        m = (a+b)/2;
        
        return getNumber(m,A);
    }
    
    int countLess(float m, vector<int>&A) {
        int i,j,n,c;
        c = 0;
        i = j = 0;
        n = A.size();
        while(i < n) {
            while(j < n && (float)A[i]/A[j] >= m) {
                j++;
            }
            
            c += n-j;
            i++;
        }
        
        return c;
    }
    
    vector<int> getNumber(float m, vector<int>&A) {
        int i,j,n;
        n = A.size();
        for(i=0;i!=n-1;i++) {
            for(j=i+1;j!=n;j++) {
                if(abs(m-(float)A[i]/A[j]) < 1e-7) {
                    return {A[i], A[j]};
                }
            }
        }
        
        return {-1,-1};
    }
};
