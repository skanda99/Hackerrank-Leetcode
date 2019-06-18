
// problem: "https://www.hackerrank.com/contests/practice-contest-iet/challenges/fill-the-tank-1"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll maxWater(vector<ll>&water)
{
    int i,x;
    stack<int>S;

    S.push(0);
    ll ans = 0;

    for(i=1;i!=water.size();i++)
    {
        if(water[S.top()] > water[i])
            S.push(i);
        else
        {
            while((!S.empty()) && water[S.top()]<=water[i])
            {
                x = S.top();
                S.pop();
            }

            if(S.empty())
                ans += min(water[i],water[x])*(i-x);

            S.push(i);
        }
    }

    if(S.size()==1)
        return ans;

    while(!S.empty())
    {
        x = S.top();
        S.pop();

        if(S.empty())
            return ans;

        ans += water[x]*(x-S.top());
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    int i;
    vector<ll>Water;
    for(i=0;i!=n;i++)
    {
        ll x;
        cin>>x;
        Water.push_back(x);
    }

    cout<<maxWater(Water);        // define

    return 0;
}
