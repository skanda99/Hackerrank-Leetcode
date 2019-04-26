
// problem: "https://www.hackerrank.com/challenges/the-quickest-way-up/problem"

#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

void initGr (vector<int>G[])
{
    int i,j;

    for(i=1;i!=101;i++)
    {
        if(G[i].size() == 0)
        {
            for(j=i+1;j<=i+6 && j<=100;j++)
                G[i].push_back(j);
        }
    }
}

int isLadder(vector<pair<int,int>>&L,int n)
{
    int i;
    for(i=0;i!=L.size();i++)
        if(L[i].first == n)
            return L[i].second;

    return -1;
}

int isSnake(vector<pair<int,int>>&S,int n)
{
    int i;
    for(i=0;i!=S.size();i++)
        if(S[i].first == n)
            return S[i].second;

    return -1;
}

int bfs(vector<int>G[],vector<pair<int,int>>&L,vector<pair<int,int>>&S)
{
    vector<bool>Visited(101,false);
    vector<int>lvl(101,-1);
    queue<int>Q;

    Q.push(1);
    Visited[1] = false;
    lvl[1] = 0;
    while(!Q.empty())
    {
        int n = Q.front();
        Q.pop();
        int i;
        for(i=0;i!=G[n].size();i++)
        {
            if(!Visited[G[n][i]])
            {
                int l = isLadder(L,G[n][i]);        // define
                int s = isSnake(S,G[n][i]);         // define

                if(l>0)
                {
                    Visited[G[n][i]] = true;
                    Visited[l] = true;
                    lvl[G[n][i]] = lvl[n]+1;
                    lvl[l] = lvl[n]+1;
                    Q.push(l);
                }
                else if(s>0)
                {
                    Visited[G[n][i]] = true;
                    Visited[s] = true;
                    lvl[G[n][i]] = lvl[n]+1;
                    lvl[s] = lvl[n]+1;
                    Q.push(s);
                }
                else
                {
                    Visited[G[n][i]] = true;
                    lvl[G[n][i]] = lvl[n]+1;
                    Q.push(G[n][i]);
                }
            }
        }
    }

    return lvl[100];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int>G[101];

        vector<pair<int,int>>L;
        while(n--)
        {
            int x,y;
            cin>>x>>y;

            pair<int,int>p(x,y);
            G[x].push_back(y);
            L.push_back(p);
        }

        int m;
        cin>>m;

        vector<pair<int,int>>S;
        while(m--)
        {
            int x,y;
            cin>>x>>y;

            pair<int,int>p(x,y);
            G[x].push_back(y);
            S.push_back(p);
        }

        initGr(G);  // define

        cout<<bfs(G,L,S)<<'\n';      // define
    }

    return 0;
}
