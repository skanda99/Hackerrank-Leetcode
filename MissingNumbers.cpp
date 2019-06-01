
// problem: "https://www.hackerrank.com/challenges/missing-numbers/problem"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,i;

    cin>>a;
    vector<int>A(a);
    for(i=0;i!=a;i++)
        cin>>A[i];

    cin>>b;
    vector<int>B(b);
    for(i=0;i!=b;i++)
        cin>>B[i];

    int m;
    //M=*max_element(B.begin(),B.end());
    m=*min_element(B.begin(),B.end());

    vector<int>ac(100);
    vector<int>bc(100);

    for(i=0;i!=b;i++)
        bc[B[i]-m]++;

    for(i=0;i!=a;i++)
        ac[A[i]-m]++;

    for(i=0;i!=100;i++)
        if(ac[i]<bc[i])
            cout<<i+m<<" ";

    return 0;
}
