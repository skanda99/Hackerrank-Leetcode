
// problem: "https://www.hackerrank.com/challenges/torque-and-development/problem"

#include<iostream>
#include<vector>
#include<queue>
#define ll long long unsigned int

using namespace std;

ll BFS(vector<int>G[],vector<int>&V,int i)
{
    V[i] = 1;
    queue<int>Q;
    Q.push(i);
    ll c = 1;

    while(!Q.empty())
    {
        int j = Q.front();
        Q.pop();

        int k;
        for(k=0;k!=G[j].size();k++)
        {
            if(V[G[j][k]] == 0)
            {
                V[G[j][k]] = 1;
                Q.push(G[j][k]);
                c++;
            }
        }
    }

    return c;
}

int main()
{
    int q;
    cin>>q;

    while(q--)
    {
        int n,m;
        ll clib,croad;
        cin>>n>>m>>clib>>croad;

        vector<int>G[n+1];
        int x,y,i;

        for(i=0;i!=m;i++)
        {
            cin>>x>>y;

            G[x].push_back(y);
            G[y].push_back(x);
        }

        vector<int>V(n+1,0);
        ll cost = 0;

        for(i=1;i!=n+1;i++)
        {
            if(V[i]==0)     // define BFS()
            {
                if(clib<croad)
                    cost += BFS(G,V,i) * clib;
                else
                    cost += clib + (BFS(G,V,i)-1) * croad;
            }
        }

        cout<<cost<<'\n';
    }

    return 0;
}
