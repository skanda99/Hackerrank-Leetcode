
// problem: "https://www.hackerrank.com/challenges/luck-balance/problem"

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i,j,K,N,T,luck[100],num;
    long long int sum=0;

    cin>>N>>K;

    j=0;
    for(i=0;i<N;i++)
    {
        cin>>num>>T;

        if(T==0)
            sum=sum+num;
        else
        {
            luck[j]=num;
            j++;
        }
    }

    sort(luck,luck+j,greater<int>());

    for(i=0;i<min(K,j);i++)
        sum=sum+luck[i];

    if(K<j)
    for(i=K;i<j;i++)
        sum=sum-luck[i];

    cout<<sum<<endl;

    return 0;
}
