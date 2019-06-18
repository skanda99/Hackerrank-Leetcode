
// problem: "https://www.hackerrank.com/contests/practice-contest-iet/challenges/lesser-primes"

#include<bits/stdc++.h>

using namespace std;

int numP(int n)
{
    vector<bool>P(n+1,1);
    int i,j;

    i = 2;
    while(i<n)
    {
        if(P[i])
        {
            j = i+i;
            while(j<=n)
            {
                P[j] = 0;
                j += i;
            }
        }
        i++;
    }

    int c = 0;
    for(i=2;i!=n;i++)
        if(P[i])
            c++;

    return c;
}

int main()
{
    int n;
    cin>>n;
    cout<<numP(n);
    return 0;
}
