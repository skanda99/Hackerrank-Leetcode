
// problem: "https://www.hackerrank.com/contests/practice-contest-iet/challenges/tgn"

#include<bits/stdc++.h>

using namespace std;

int calcK(vector<int>&V,int g,int l,int r)
{
    if(l>r)
        return 0;

    int m = (l+r)/2;
    int i,N;
    N = V.size();
    for(i=g+1;i<N;i++)
    {
        if(V[i]<m*V[i-g])
        {
            return max(0,calcK(V,g,l,m-1));
        }
    }

    return max(m,calcK(V,g,m+1,r));
}

int MaxPosK(vector<int>&V,int g,vector<int>&maxK)
{
    if(maxK[g] == -1)
    {
        // calculate max K for g which makes beautiful array
        int k = calcK(V,g,1,1000);     // define

        maxK[g] = k;
    }

    return maxK[g];
}

int main()
{
    int n,m,q;
    cin>>n>>m>>q;

    vector<int>V;
    int x,i;
    V.push_back(-1);
    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    sort(V.begin()+1,V.end());

    vector<int>G;
    G.push_back(-1);
    for(i=0;i!=m;i++)
    {
        cin>>x;
        G.push_back(x);
    }

    int k,j;
    vector<int>maxK(n,-1);
    for(i=0;i!=q;i++)
    {
        cin>>k>>j;
        int g = G[j];

        int K = MaxPosK(V,g,maxK);       // define

        if(k<=K)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }

    return 0;
}
