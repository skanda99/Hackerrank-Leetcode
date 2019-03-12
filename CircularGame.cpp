
// problem: "https://www.hackerrank.com/contests/bfme-2/challenges/circular-card-game"

#include<iostream>
#include<vector>

using namespace std;

int comp(int x)
{
    if(x==0)
        return 1;

    if(x==1)
        return 0;

    return -1;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>V(n);
        int i;

        for(i=0;i!=n;i++)
            cin>>V[i];

        for(i=0;i!=n;i++)
        {
            if(V[i]==1)
            {

                V[i] = -1;

                if(i==0)
                    V[n-1] = comp(V[n-1]);
                else
                    V[i-1] = comp(V[i-1]);


                if(i==n-1)
                    V[0] = comp(V[0]);
                else
                    V[i+1] = comp(V[i+1]);      // define

                int j = i-1;
                while(j>=0 && V[j]==1)
                {
                    if(j==0)
                    {
                        V[0] = -1;
                        V[n-1] = comp(V[n-1]);
                        break;
                    }

                    V[j] = -1;
                    V[j-1] = comp(V[j-1]);
                    j--;
                }
            }
        }

        int c = 0;
        for(i=0;i!=n;i++)
            if(V[i] == 0)
                c = 1;

        if(n==2 && V[0]!=V[1])
            c = 0;


        if(c == 1)
            cout<<"No\n";
        else
            cout<<"Yes\n";

    }

    return 0;
}
