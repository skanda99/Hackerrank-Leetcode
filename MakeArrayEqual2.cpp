
// problem: "https://www.hackerrank.com/contests/practice-contest-iet/challenges/make-array-equal-ii"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<bool>V;
    int x,i;
    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    int j,c;
    j = i = n-1;
    c = 0;

    vector<bool>B(V);
    sort(B.begin(),B.end());

    while(i>=0)
    {
        if(V[i]==B[j])
        {
            i--;
            j--;
        }
        else
        {
            while(i>=0 && V[i]!=B[j])
                i--;

            c += j-i;
            swap(V[i],V[j]);
            j--;
            //i--;
        }
    }


    cout<<c;

    return 0;
}
