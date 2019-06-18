
// problem: "https://www.hackerrank.com/contests/practice-contest-iet/challenges/date-hour"

#include<bits/stdc++.h>
#define ll long long
#define p (ll)(1e9+7)

using namespace std;

ll Fear(vector<ll>&V)
{
    stack<ll>S;

    ll i,ans,x;
    ans = 1;
    for(i=0;i!=V.size();i++)
    {
        if(S.empty())
            S.push(i);
        else
        {
            if(V[S.top()] <= V[i])
                S.push(i);
            else
            {
                while(!S.empty() && V[S.top()]>V[i])
                {
                    x = S.top();
                    S.pop();

                    ans = (ans*(i-x+1))%p;
                }

                S.push(i);
            }
        }
    }

    return ans;
}

int main()
{
    int x,n,k;
    cin>>n>>k;

    vector<ll>V;
    int i;
    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    cout<<Fear(V);      // define

    return 0;
}
