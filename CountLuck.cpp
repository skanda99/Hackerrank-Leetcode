
// problem: "https://www.hackerrank.com/challenges/count-luck/problem"

#include<bits/stdc++.h>
#define ll long long
#define p (ll)(-1e9)

using namespace std;

bool isValid(vector<string>&M,int x,int y,int n,int m)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;

    if(M[x][y] == 'X')
        return false;

    return true;
}

int dfs(vector<string>&M,int x,int y,int n,int m)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return p;

    if(M[x][y] == 'X')
        return p;

    if(M[x][y] == '*')
        return 0;

    int c = 0;
    M[x][y] = 'X';

    if(isValid(M,x+1,y,n,m))      // define
        c++;

    if(isValid(M,x-1,y,n,m))
        c++;

    if(isValid(M,x,y+1,n,m))
        c++;

    if(isValid(M,x,y-1,n,m))
        c++;

    int C;
    C = c;

    c = max(dfs(M,x+1,y,n,m),0);
    c = max(dfs(M,x-1,y,n,m),c);
    c = max(dfs(M,x,y+1,n,m),c);
    c = max(dfs(M,x,y-1,n,m),c);

    if(C>1)
        return c+1;

    return c;
}

int countWand(vector<string>&M,int n,int m)
{
    int x,y;
    int i,j;

    for(i=0;i!=n;i++)
        for(j=0;j!=m;j++)
            if(M[i][j] == 'M')
            {
                x = i;
                y = j;
            }

    int wand = dfs(M,x,y,n,m);      // define

    return wand;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int i;
        vector<string>M;
        for(i=0;i!=n;i++)
        {
            string x;
            cin>>x;
            M.push_back(x);
        }

        int k;
        cin>>k;

        int K = countWand(M,n,m);       // define
        if(k == K)
            cout<<"Impressed\n";
        else
            cout<<"Oops!\n";
    }

    return 0;
}
