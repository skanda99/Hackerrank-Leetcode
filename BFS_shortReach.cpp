
// problem: "https://www.hackerrank.com/challenges/bfsshortreach/problem"

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void BFS(vector<int>G[],int n,int s)
{
    queue<int>Q;
    vector<int>V(n+1,-1);
    Q.push(s);

    V[s] = 0;
    while(!Q.empty())
    {
        int i = Q.front();
        Q.pop();

        int j;
        for(j=0;j!=G[i].size();j++)
        {
            if(V[G[i][j]]==-1)
            {
                V[G[i][j]] = V[i]+1;
                Q.push(G[i][j]);
            }
        }
    }

    int i;
    for(i=1;i!=n+1;i++)
    {
        if(i!=s)
        {
            if(V[i]==-1)
                cout<<-1<<' ';
            else
                cout<<V[i]*6<<' ';
        }
    }

    cout<<'\n';
}

int main()
{
    int q;
    cin>>q;

    while(q--)
    {
        int n,m;

        cin>>n>>m;
        vector<int>G[n+1];

        int x,y;
        while(m--)
        {
            cin>>x>>y;

            G[x].push_back(y);
            G[y].push_back(x);
        }

        int s;
        cin>>s;

        BFS(G,n,s);       // define
    }

    return 0;
}
