
// problem: "https://www.hackerrank.com/challenges/knightl-on-chessboard/problem"

#include<bits/stdc++.h>
#define Pair pair<int,int>

using namespace std;

struct node
{
    int x,y,s;

    node(int x,int y,int s): x(x),y(y),s(s) {}
};

int minSteps(int a,int b,int n)
{
    queue<node>Q;
    Q.push(node(0,0,0));
    vector<vector<int>>V(n,vector<int>(n,-1));

    while(!Q.empty())
    {
        node p = Q.front();
        Q.pop();


        if(p.x == n-1 && p.y == n-1)
            return p.s;

        if(p.x<0 || p.x>=n || p.y<0 || p.y>=n || V[p.x][p.y] != -1)
            continue;

        V[p.x][p.y] = 1;

        Q.push(node(p.x+a,p.y+b,p.s+1));
        Q.push(node(p.x+a,p.y-b,p.s+1));
        Q.push(node(p.x-a,p.y+b,p.s+1));
        Q.push(node(p.x-a,p.y-b,p.s+1));
        Q.push(node(p.x+b,p.y+a,p.s+1));
        Q.push(node(p.x+b,p.y-a,p.s+1));
        Q.push(node(p.x-b,p.y+a,p.s+1));
        Q.push(node(p.x-b,p.y-a,p.s+1));
    }

    return -1;
}

int main()
{
    int n,i,j;

    cin>>n;

    for(i=1;i!=n;i++)
    {
        for(j=1;j!=n;j++)
            cout<<minSteps(i,j,n)<<' ';        // define

        cout<<'\n';
    }

    return 0;
}
