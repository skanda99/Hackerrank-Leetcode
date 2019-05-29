
// problem: "https://www.hackerrank.com/challenges/icecream-parlor/problem"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,n,t,m,x,y;

    cin>>t;

    for(i=0;i!=t;i++)
    {
        cin>>m>>n;

        vector<int>flavours(n);
        for(j=0;j!=n;j++)
            cin>>flavours[j];

        vector<int>copy(flavours);

        sort(flavours.begin(),flavours.end());

        //for(j=0;j!=n;j++)
        //    cout<<flavours[j]<<" ";

        //cout<<'\n';

        j=0;
        while(1)
        {
            if(m-flavours[j]!=flavours[j])
            {
                if(binary_search(flavours.begin(),flavours.end(),m-flavours[j]))
                {
                    x=flavours[j];
                    y=m-flavours[j];

                    for(int k=0;k!=n;k++)
                    {
                        if(x==copy[k])
                            cout<<k+1<<" ";

                        else if(y==copy[k])
                            cout<<k+1<<" ";
                    }

                    cout<<'\n';
                    break;
                }
            }

            else
            {
                if(flavours[j+1]==flavours[j])
                {
                    x=y=flavours[j];
                    for(int k=0;k!=n;k++)
                    {
                        if(x==copy[k])
                            cout<<k+1<<" ";

                        else if(y==copy[k])
                            cout<<k+1<<" ";
                    }

                    cout<<'\n';
                    break;
                }
            }

            j++;
        }
    }

    return 0;
}
