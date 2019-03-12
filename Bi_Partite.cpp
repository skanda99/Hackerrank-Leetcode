
// problem: "https://www.hackerrank.com/contests/bfme-2/challenges/make-a-bi-partition-easy"

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int parent(vector<int>&P,int p)
{
    while(P[p]!=-1)
        p = P[p];

    return p;
}

void printH(vector<pair<int,int>>&E,int n)
{
    vector<pair<int,int>>H;
    vector<int>P(n+1,-1);

    int i;
    for(i=0;i!=E.size();i++)
    {
        int p1 = parent(P,E[i].first);      // define
        int p2 = parent(P,E[i].second);

        if(p1 != p2)
        {
            H.push_back(E[i]);
            P[p2] = p1;
        }
    }

    cout<<H.size()<<'\n';

    for(i=0;i!=H.size();i++)
        cout<<H[i].first<<' '<<H[i].second<<'\n';

    return;
}


int main()
{
    int n,m;

    cin>>n>>m;
    vector<int>G[n+1];
    vector<pair<int,int>>E;

    int i;
    for(i=0;i!=m;i++)
    {
        int u,v;

        cin>>u>>v;

        pair<int,int>p(u,v);
        E.push_back(p);
    }

    printH(E,n);

    return 0;
}
