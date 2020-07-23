
// problem: "https://leetcode.com/problems/count-vowels-permutation/"

#define p (int)(1e9+7)

class Solution {
public:
    int countVowelPermutation(int n) {
        
        int i,a1,e1,i1,o1,u1,a2,e2,i2,o2,u2;
        a1 = e1 = i1 = o1 = u1 = 1;
        
        for(i=2;i!=n+1;i++) {
            a2 = e1;
            e2 = (a1+i1)%p;
            i2 = ((a1+e1)%p+(o1+u1)%p)%p;
            o2 = (i1+u1)%p;
            u2 = a1;
            
            a1 = a2;
            e1 = e2;
            i1 = i2;
            o1 = o2;
            u1 = u2;
        }
        
        return ((((a1 + e1)%p + i1)%p + o1)%p + u1)%p;
    }
};
