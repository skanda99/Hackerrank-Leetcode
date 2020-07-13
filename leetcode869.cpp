
// problem: "https://leetcode.com/problems/reordered-power-of-2/"

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        
        int i;
        unordered_set<string>S;
        for(i=1;i<=(int)1e9;i*=2)
            S.insert(getDCS(i));
        
        if(S.count(getDCS(N)))
            return true;
        
        return false;
    }
    
    string getDCS(int p)
    {
        vector<int>V(10,0);
        while(p)
        {
            V[p%10]++;
            p /= 10;
        }
        
        string s = "";
        int i;
        for(i=0;i!=10;i++)
            s += string(1,V[i]+'0');
        
        return s;
    }
};
