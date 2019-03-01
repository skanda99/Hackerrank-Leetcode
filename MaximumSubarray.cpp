
// problem: "https://www.hackerrank.com/challenges/maxsubarray/problem"
// The Maximum Subarray

#include<iostream>
#include<vector>

using namespace std;

int subarray(vector<int>&V)
{
    int n = V.size();
    vector<int>S(n+1);

    int i;
    S[0] = 0;
    for(i=1;i!=n+1;i++)
        S[i] = S[i-1]+V[i-1];

    vector<int>M(n+1);
    M[n] = S[n];
    for(i=n-1;i>=0;i--)
        M[i] = max(M[i+1],S[i]);

    int m = S[1];
    for(i=0;i!=n+1;i++)
        m = max(m,M[i]-S[i]);

    if(m==0)
    {
        int Max = V[0];
        for(i=0;i!=n;i++)
            Max = max(Max,V[i]);

        m = Max;
    }

    return m;
}

int subseq(vector<int>&V)
{
    int i,M,n,S;
    n = V.size();
    S = 0;
    M = V[0];

    for(i=0;i!=n;i++)
    {
        if(V[i]>=0)
            S += V[i];

        M = max(M,V[i]);
    }

    if(S==0)
        S = M;

    return S;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;

        cin>>n;
        vector<int>V(n);

        int i;
        for(i=0;i!=n;i++)
            cin>>V[i];

        cout<<subarray(V)<<' '<<subseq(V)<<'\n';
    }

    return 0;
}
