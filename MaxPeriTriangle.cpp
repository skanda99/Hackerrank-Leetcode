
// problem: "https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem"

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,i,j;
    long long int L[50];

    cin>>n;
    for(i=0;i<n;i++)
        cin>>L[i];

    sort(L,L+n,greater<long long int>());

    j=-1;
    for(i=0;i<n-2;i++)
        if(L[i]<L[i+1]+L[i+2])
        {
            cout<<L[i+2]<<" "<<L[i+1]<<" "<<L[i]<<endl;
            j=0;
            break;
        }

    if(j==-1)
        cout<<-1<<endl;

    return 0;
}
