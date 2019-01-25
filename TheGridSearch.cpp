
// problem: "https://www.hackerrank.com/challenges/the-grid-search/problem"

#include<iostream>

using namespace std;

char G[1000][1000],g[1000][1000];

bool search(int I,int J,int r,int c)
{
    int i,j;
    
    for(i=0;i!=r;i++)
        for(j=0;j!=c;j++)
            if(g[i][j]!=G[i+I][j+J])
                return 0;
    
    return 1;
}

int main()
{
    int R,C,r,c,i,j,T;
    
    cin>>T;
    for(int t=0;t!=T;t++)
    {
        cin>>R>>C;
        for(i=0;i!=R;i++)
            cin>>G[i];
        
        cin>>r>>c;
        for(i=0;i!=r;i++)
            cin>>g[i];
        
        int y = 0;
        for(i=0;i!=R-r+1;i++)
        {
            for(j=0;j!=C-c+1;j++)
                if(G[i][j]==g[0][0])
                {
                    
                    y = search(i,j,r,c);
                    
                    if(y==1)
                        break;
                    
                }
            if(y==1)
                break;
        }
        if(y==1)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    return 0;
}