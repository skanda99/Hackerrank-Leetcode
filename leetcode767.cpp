
// problem: "https://leetcode.com/problems/reorganize-string/"

struct Pair
{
    int n;
    char c;
    
    Pair(int n,char c) : n(n), c(c) { }
};

struct compN
{
    bool operator()(Pair &p1, Pair &p2)
    {
        return p1.n < p2.n;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        
        vector<int>V(26,0);
        int i,n;
        n = S.size();
        
        for(i=0;i!=n;i++)
            V[S[i]-'a'] ++;
        
        priority_queue<Pair,vector<Pair>,compN>Q;       // define
        for(i=0;i!=26;i++)
            if(V[i])
                Q.push(Pair(V[i],'a'+i));
        
        S = "";
        construct(S,Q);
            
        return S;
    }
    
    void construct(string &s,priority_queue<Pair,vector<Pair>,compN>&Q)
    {
        while(Q.size() >= 2)
        {
            Pair p1 = Q.top();
            Q.pop();
            
            Pair p2 = Q.top();
            Q.pop();
            
            if(s.empty())
            {
                s.append(string(1,p1.c));
                s.append(string(1,p2.c));            
            }
            else
            {
                if(s[s.size()-1] == p1.c)
                {
                    s.append(string(1,p2.c));
                    s.append(string(1,p1.c));   
                }
                else
                {
                    s.append(string(1,p1.c));
                    s.append(string(1,p2.c));       
                }
            }
            
            p1.n--;
            p2.n--;
            
            if(p1.n > 0)
               Q.push(p1);
            
            if(p2.n > 0)
               Q.push(p2);
        }
        
        if(Q.size() == 1)
        {
            Pair p = Q.top();
            if(p.n > 1)
                s = "";
            else if(p.n == 1 && s[s.size()-1] == p.c)
                s = "";
            else
                s.append(string(1,p.c));   
        }
    }
}; 
