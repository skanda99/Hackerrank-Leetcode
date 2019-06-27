
// problem: "https://www.hackerrank.com/challenges/beautiful-pairs/problem"

#include<iostream>

using namespace std;

int main()
{
    int N,i,j,ca[1005],cb[1005],n,sum,x,y;


    for(i=0;i<1005;i++)
    {
        ca[i]=cb[i]=0;
    }

    cin>>N;

    for(i=0;i<N;i++)
    {
        cin>>n;
        ca[n]++;
    }

    for(j=0;j<N;j++)
    {
        cin>>n;
        cb[n]++;
    }

    j=sum=0;

    /*
    for(i=0;i<=1000;i++)
        cout<<ca[i]<< " ";

    cout<<endl;



    for(i=0;i<=1000;i++)
        cout<<cb[i]<< " ";
    */

    x=y=0;

    for(i=1;i<=1000;i++)
    {

        sum=sum+min(ca[i],cb[i]);

        if(ca[i]>cb[i])
            x=1;

        if(ca[i]<cb[i])
            y=1;

    }
    /*
    int c=0;
    cout<<endl;
    for(i=0;i<1001;i++)
        c=c+ca[i];

    cout<<c;

    cout<<endl;
    */
    if((x==1)&&(y==1))
        sum++;
    else
        sum--;

    if(N!=1)
        cout<<sum<<endl;
    else
        cout<<0<<endl;

    return 0;
}
