
// problem: "https://www.hackerrank.com/challenges/ctci-merge-sort/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll merge(vector<int>&A,vector<int>&left,vector<int>&right)
{
    int i,j,k,n,m;
    ll c;
    n = left.size();
    m = right.size();
    i = j = k = c = 0;

    while(i<n && j<m)
    {
        if(left[i] <= right[j])
        {
            A[k] = left[i];
            i++;
            k++;
        }
        else
        {
            A[k] = right[j];
            c += n-i;
            k++;
            j++;
        }
    }

    while(i<n)
    {
        A[k] = left[i];
        i++;
        k++;
    }

    while(j<m)
    {
        A[k] = right[j];
        j++;
        k++;
    }

    return c;
}

ll mergeSort(vector<int>&A)
{
    vector<int>left,right;
    int i,n;
    ll c = 0;
    n = A.size();
    if(n>1)
    {
        for(i=0;i<n;i++)
        {
            if(i<n/2)
                left.push_back(A[i]);
            else
                right.push_back(A[i]);
        }

        c += mergeSort(left);
        c += mergeSort(right);

        c += merge(A,left,right);   // define

        return c;
    }

    return 0;
}

int main()
{
    int d;
    cin>>d;

    while(d--)
    {
        int n,i;
        cin>>n;
        vector<int>V(n);
        for(i=0;i!=n;i++)
            cin>>V[i];

        cout<<mergeSort(V)<<'\n';   // define
    }

    return 0;
}
