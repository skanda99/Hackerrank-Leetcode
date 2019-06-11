
// problem:"https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem"

#include<bits/stdc++.h>

using namespace std;

int n,m,Count;

void DFS (int a[][10],int i,int j)
{
    if(a[i][j]==1)
    {
        a[i][j]=0;
        Count++;
    }
    else
        return;

    if(j-1>=0)
        DFS(a,i,j-1);

    if(j-1>=0&&i+1<n)
        DFS(a,i+1,j-1);

    if(i+1<n)
        DFS(a,i+1,j);

    if(i+1<n&&j+1<m)
        DFS(a,i+1,j+1);

    if(j+1<m)
        DFS(a,i,j+1);

    if(j+1<m&&i-1>=0)
        DFS(a,i-1,j+1);

    if(i-1>=0)
        DFS(a,i-1,j);

    if(i-1>=0&&j-1>=0)
        DFS(a,i-1,j-1);

    return;
}

int main()
{
    int a[10][10];
    int i,j;

    cin>>n>>m;
    for(i=0;i!=n;i++)
        for(j=0;j!=m;j++)
            cin>>a[i][j];

    int Max=0;

    for(i=0;i!=n;i++)
    {
        for(j=0;j!=m;j++)
        {
            Count=0;
            DFS(a,i,j);
            if(Count>Max)
                Max=Count;
        }
    }

    cout<<Max;

    return 0;
}
