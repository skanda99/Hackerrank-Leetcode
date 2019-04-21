
// problem: "https://www.hackerrank.com/challenges/countingsort2/problem"


#include<iostream>

using namespace std;

int main()
{
    long int i,j,n,a[100];
    int c;

    for(i=0;i<100;i++)
        a[i]=0;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c;

        a[c]++;
    }

    for(i=0;i<100;i++)
    {
        for(j=0;j<a[i];j++)
            cout<<i<<" ";
    }

    return 0;
}
