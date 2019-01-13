
// problem: "https://www.hackerrank.com/challenges/circular-array-rotation/problem"

#include <iostream>

using namespace std;

int main()
{
    unsigned long int a[1000000],k,n,m[5000];
    unsigned long int q,K;

    cin>>n>>k>>q;
    K=k%n;

    for(k=0;k<n;k++)
        cin>>a[k];

    for(k=0;k<q;k++)
        cin>>m[k];

    for(k=0;k<q;k++)
    {
        if(m[k]>=K)
            cout<<a[m[k]-K]<<endl;
        else
            cout<<a[m[k]-K+n]<<endl;
    }

    return 0;
}
