
// problem: "https://www.hackerrank.com/challenges/ctci-bubble-sort/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=sorting"

#include<bits/stdc++.h>

using namespace std;

void BubbleSort(vector<int>&A,int n)
{
    int i,j,c;
    c = 0;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                c++;
                swap(A[j],A[j+1]);
            }
        }
    }

    cout<<"Array is sorted in "<<c<<" swaps.\n";
    cout<<"First Element: "<<A[0]<<'\n';
    cout<<"Last Element: "<<A[n-1]<<'\n';
}

int main()
{
    int n,i;
    cin>>n;
    vector<int>A(n);
    for(i=0;i!=n;i++)
        cin>>A[i];

    BubbleSort(A,n);        // define

    return 0;
}
