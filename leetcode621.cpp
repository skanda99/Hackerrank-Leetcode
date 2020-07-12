
// problem: "https://leetcode.com/problems/task-scheduler/"

struct node
{
    int n,i;
    char c;
    
    node(int n,char c,int i) : n(n), c(c), i(i) { }
};

struct compN
{
    bool operator()(node &p1,node &p2)
    {
        return p1.n < p2.n;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<node,vector<node>,compN>PQ;
        queue<node>Q;
        
        int i,m;
        m = tasks.size();
        vector<int>V(26,0);
        for(i=0;i!=m;i++)
            V[tasks[i]-'A']++;
        
        for(i=0;i!=26;i++)
            if(V[i])
                PQ.push(node(V[i],i+'A',-n-1));
        
        i = 0;
        while(!PQ.empty() || !Q.empty())
        {
            if(!Q.empty() && i-Q.front().i-1>=n)
            {
                PQ.push(Q.front());
                Q.pop();
            }
            
            if(PQ.empty())
                i++;
            
            else
            {
                node p = PQ.top();
                PQ.pop();
                
                p.n--;
                if(p.n > 0)
                    Q.push(node(p.n,p.c,i));
                
                i++;
            }
        }
        
        return i;
    }
};
