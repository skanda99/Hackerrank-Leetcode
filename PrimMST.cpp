
// problem: "https://www.hackerrank.com/challenges/primsmstsub/problem"

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

struct Node
{
    int w,x,y;

    Node(int w,int x,int y): w(w),x(x),y(y) { }

};

struct func
{
        bool operator()(Node const&p1,Node const&p2)
        {
            return p1.w>p2.w;
        }
};

int prim(vector<pair<int,int>>G[],int n,int start)
{
    vector<bool>Vis(n+1,false);
    priority_queue<Node,vector<Node>,func>Q;
    int c = 1;
    int mst = 0,cn;

    cn = start;
    Vis[cn] = true;
    while(c!=n)
    {
        int i;
        for(i=0;i!=G[cn].size();i++)
        {
            if(!Vis[G[cn][i].first])
            {
                Node p(G[cn][i].second,cn,G[cn][i].first);
                Q.push(p);
            }
        }

        while(!Q.empty())
        {
            Node p = Q.top();

            if(!Vis[p.y])
            {
                mst += p.w;
                c++;
                cn = p.y;
                Vis[cn] = true;
                Q.pop();
                break;
            }

            Q.pop();
        }


        //cout<<c<<' '<<mst<<'\n';
    }

    return mst;
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>G[n+1];
    int i;
    for(i=0;i!=m;i++)
    {
        int x,y,w;

        cin>>x>>y>>w;

        pair<int,int>p1(y,w);
        pair<int,int>p2(x,w);

        G[x].push_back(p1);
        G[y].push_back(p2);
    }

    int start;
    cin>>start;

    cout<<prim(G,n,start);    // define

    return 0;
}
