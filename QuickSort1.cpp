
// problem: "https://www.hackerrank.com/challenges/quicksort1/problem"

#include<iostream>

using namespace std;

int main()
{
    int n,a[1000],p,left[1000],right[1000],i,ls,rs;

    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    p=a[0];
    ls=rs=0;

    for(i=1;i<n;i++)
    {
        if(a[i]<p)
        {
            left[ls]=a[i];
            ls++;
        }
        else
        {
            right[rs]=a[i];
            rs++;
        }
    }

    for(i=0;i<ls;i++)
        a[i]=left[i];

    a[ls]=p;

    for(i=ls+1;i<rs+ls+1;i++)
        a[i]=right[i-ls-1];

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
