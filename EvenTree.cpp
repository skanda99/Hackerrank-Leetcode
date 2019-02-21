
// problem: "https://www.hackerrank.com/challenges/even-tree/problem"
// Even Tree

#include<iostream>
#include<vector>

using namespace std;

vector<int>N(101,-1);
vector<int>V(101,-1);
vector<int>V2(101,-1);


int nodes(vector<int>G[],int i)
{
    if(N[i] == -1)
    {
        V[i] = 1;
        int c = 0;
        int j;
        for(j=0;j!=G[i].size();j++)
        {
            if(V[G[i][j]]!=1)
            {
                V[G[i][j]] = 1;
                c = c+1+nodes(G,G[i][j]);
            }
        }
        N[i] = c;
    }

    return N[i];
}

int countCut(vector<int>G[],int i)
{
    V2[i] = 1;
    int j,c;

    c = 0;
    for(j=0;j!=G[i].size();j++)
    {
        if(V2[G[i][j]]==-1)
        {
            if(N[G[i][j]]%2)
            {
                c++;
            }

            c += countCut(G,G[i][j]);
        }
    }

    return c;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>G[n+1];
    while(m--)
    {
        int x,y;
        cin>>x>>y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    N[1] = nodes(G,1);

    cout<<countCut(G,1);

    return 0;
}
