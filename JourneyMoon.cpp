
// problem: "https://www.hackerrank.com/challenges/journey-to-the-moon/problem"

#include<iostream>
#include<vector>
#include<queue>
#define ll long long unsigned int

using namespace std;

ll BFS (vector<int>G[],vector<bool>&V,int i)
{
    queue<int>Q;
    ll c = 1;
    Q.push(i);

    while(!Q.empty())
    {
        int j = Q.front();
        Q.pop();

        int k;
        for(k=0;k!=G[j].size();k++)
        {
            if(V[G[j][k]]==0)
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
    int n,p;
    cin>>n>>p;

    int x,y;
    vector<int>G[n];
    while(p--)
    {
        cin>>x>>y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<bool>V(n,0);

    int i;
    ll c,s;
    c = s = 0;
    for(i=0;i!=n;i++)
    {
        if(V[i]==0)
        {
            V[i] = 1;

            x = BFS(G, V, i);       // define function
            c += s * x;
            s += x;

            //cout<<x<<' ';
        }
    }

    cout<<c;

    return 0;
}
