
// problem: "https://leetcode.com/problems/cheapest-flights-within-k-stops/"

struct node
{
    int v,w,s;
    node(int v,int w,int s=-1) : v(v), w(w), s(s) { }
};

struct compW
{
    bool operator()(node &p1, node&p2)
    {
        return p1.w > p2.w;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<node>G[n+1];
        int i;
        for(i=0;i!=flights.size();i++)
            G[flights[i][0]].push_back(node(flights[i][1],flights[i][2]));
        
        return minCost(G,src,dst,K,n);
    }
    
    int minCost(vector<node>G[],int s,int d,int k,int n)
    {
        priority_queue<node,vector<node>,compW>Q;
        Q.push(node(s,0,0));
        vector<vector<int>>V(n,vector<int>(k+2,-1));

        while(!Q.empty())
        {
            node p = Q.top();
            Q.pop();
            
            if(V[p.v][p.s] != -1)
                continue;
            
            V[p.v][p.s] = p.w;
            int i;
            for(i=0;i!=G[p.v].size();i++)
                if(p.s+1 <= k+1 && V[G[p.v][i].v][p.s+1] == -1)
                    Q.push(node(G[p.v][i].v, G[p.v][i].w+p.w, p.s+1));
        }
        
        int i,m;
        m = INT_MAX;
        for(i=0;i!=k+2;i++)
            if(V[d][i] != -1)
                m = min(m,V[d][i]);
        
        if(m == INT_MAX)
            m = -1;
        
        return m;
    }
};
