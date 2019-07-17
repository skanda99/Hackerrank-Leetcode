
// problem: "https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=arrays"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int i;
    vector<int>V(n+1);
    for(i=1;i!=n+1;i++)
        cin>>V[i];

    vector<int>Index(n+1);
    for(i=1;i!=n+1;i++)
        Index[V[i]] = i;

    int c = 0;
    for(i=1;i!=n+1;i++)
    {
        if(i != V[i])
            c++;

        swap(V[i],V[Index[i]]);
        swap(Index[i],Index[V[Index[i]]]);
    }

    cout<<c;
    
    return 0;
}
