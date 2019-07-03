
// problem: "https://www.hackerrank.com/challenges/largest-permutation/problem"

#include<iostream>

using namespace std;

int main()
{
    long long int i,j,N,K,a[100000],p,b[100001];

    cin>>N>>K;

    for(i=0;i<N;i++)
        cin>>a[i];

    for(i=0;i<N;i++)
        b[a[i]]=i;

    p=0; j=N;

    for(i=0;i<N;i++,j--)
    {
        if((a[i]!=j)&&(p<K))
        {
            cout<<j<<" ";
            a[b[j]]=a[i];
            b[a[i]]=b[j];
            p++;
        }
        else
            cout<<a[i]<<" ";
    }

    return 0;

}
