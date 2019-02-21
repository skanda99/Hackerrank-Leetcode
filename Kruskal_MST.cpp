
// problem: "https://www.hackerrank.com/challenges/kruskalmstrsub/problem"
// Kruskal (MST): Really Special Subtree

#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long int

using namespace std;

struct edge
{
    int u,v,w;
};

bool func(edge edge1,edge edge2)
{
    return (edge1.w<edge2.w);
}

int Parent(vector<int>&P,int p)
{
    while(P[p]!=-1)
        p = P[p];

    return p;
}

ll Kruskal(vector<edge>&Edges,int n,int m)
{
    vector<int>P(n+1,-1);

    int i,c;
    c = 0;
    ll t = 0;
    for(i=0;i!=Edges.size();i++)
    {
        if(c == n-1)
            break;

        int p1 = Parent(P,Edges[i].u);
        int p2 = Parent(P,Edges[i].v);

        if(p1 != p2)
        {
            P[p1] = p2;
            c++;
            t += Edges[i].w;
        }
    }

    return t;
}

int main()
{
    int n,m;
    cin>>n>>m;

    int M;
    M = m;

    vector<edge>Edges;
    while(M--)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edge E;
        E.u = u;
        E.v = v;
        E.w = w;

        Edges.push_back(E);
    }

    sort(Edges.begin(),Edges.end(),func);

    ll min_wt = Kruskal(Edges,n,m);

    cout<<min_wt;

    return 0;
}
