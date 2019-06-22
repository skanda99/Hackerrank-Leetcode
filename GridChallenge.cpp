
// problem: "https://www.hackerrank.com/challenges/grid-challenge/problem"

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i,j,T,n;
    char G[100][100],minr,minc;

    cin>>T;

    for(int k=0;k<T;k++)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>G[i];

        for(i=0;i<n;i++)
            sort(G[i],G[i]+n);

        for(j=0;j<n;j++)
        {
            for(i=0;i<n-1;i++)
                if(G[i][j]>G[i+1][j])
                {
                    cout<<"NO"<<endl;
                    n=-1;
                    break;
                }

            if(n==-1)
                break;
        }

        if(n!=-1)
            cout<<"YES"<<endl;
    }

    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<G[i][j];

        cout<<endl;
    }
    */
    return 0;
}
