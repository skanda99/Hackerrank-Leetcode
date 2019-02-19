
// problem: "https://www.hackerrank.com/challenges/cut-the-tree/problem"

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int>V(100001,0);
vector<int>SS(100001,0);
vector<int> data;

int SumSubtree(vector<int>G[],int i)
{
    if(V[i]==1)
        return 0;

    V[i] = 1;

    int j;
    for(j=0;j!=G[i].size();j++)
        SS[i] += SumSubtree(G,G[i][j]);

    SS[i] += data[i-1];

    return SS[i];
}

int main()
{
    int n;
    cin>>n;

    int i;

    for(i=0;i!=n;i++)
    {
        int x;
        cin>>x;
        data.push_back(x);
    }

    vector<int>G[n+1];
    for(i=0;i!=n;i++)
    {
        int x,y;
        cin>>x>>y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    int T = SumSubtree(G,1);    // define function

    int m = T;
    for(i=2;i!=n+1;i++)
    {
        if(abs(2*SS[i]-T) < m)
            m =  abs(2*SS[i]-T);
    }

    cout<<m;

    return 0;
}
