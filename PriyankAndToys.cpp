
// problem: "https://www.hackerrank.com/challenges/priyanka-and-toys/problem"

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int i,j,N,count;
    int W[100000],w;

    cin>>N;
    for(i=0;i<N;i++)
        cin>>W[i];

    sort(W,W+N);

    w=W[0];
    count=1;

    for(j=0;j<N;j++)
        if(W[j]>w+4)
        {
            count++;
            w=W[j];
        }

    cout<<count<<endl;

    return 0;
}
