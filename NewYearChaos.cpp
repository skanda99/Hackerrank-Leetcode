
// problem: "https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=arrays"

#include<bits/stdc++.h>

using namespace std;

int countBribes(vector<int>&V,int n)
{
    int i;
    stack<int>S1;

    S1.push(V[0]);

    stack<int>S2;
    vector<int>A(n+1,0);
    for(i=1;i!=n;i++)
    {
        while(!S1.empty() && S1.top()>V[i])
        {
            S2.push(S1.top());
            A[S1.top()]++;

            if(A[S1.top()]>2)
                return -1;

            S1.pop();
        }

        S1.push(V[i]);

        while(!S2.empty())
        {
            S1.push(S2.top());
            S2.pop();
        }
    }

    int S = 0;
    for(i=1;i!=n+1;i++)
        S += A[i];

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

        int ans = countBribes(V,n);

        if(ans == -1)
            cout<<"Too chaotic\n";       // define
        else
            cout<<ans<<'\n';
    }

    return 0;
}
