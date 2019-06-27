
// problem: "https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem"

#include<iostream>

using namespace std;

int main()
{
    int T,k;
    long long int i,j,y,N;

    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>N;
        y=-1;
        for(j=0;j*5<=N;j++)
        {
            if((N-(5*j))%3==0)
            {
                y=0;
                for(k=1;k<=(N-(5*j));k++)
                    cout<<5;

                for(k=(N-(5*j))+1;k<=N;k++)
                    cout<<3;

                break;
            }
        }

        if(y==-1)
            cout<<-1;

        cout<<endl;
    }

    return 0;
}
