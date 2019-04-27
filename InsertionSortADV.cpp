
// problem: "https://www.hackerrank.com/challenges/insertion-sort/problem"

#include<iostream>
#include<vector>

using namespace std;

long long int c = 0;

void mergeSort(vector<int>&A,int n)
{
    int m = n/2;

    if(m==0)
        return;

    int i;

    vector<int>L;
    for(i=0;i!=m;i++)
        L.push_back(A[i]);

    vector<int>R;
    for(i=m;i!=n;i++)
        R.push_back(A[i]);

    // mergeSort L and R

    mergeSort(L,m);
    mergeSort(R,n-m);

    // merge the two arrays

    int j = 0,k = 0;
    i = k = 0;

    while(i<m && j<n-m)
    {
        if(L[i]<=R[j])
        {
            A[k] = L[i];
            i++;
            k++;
        }
        else
        {   // if L[i]>R[j]
            A[k] = R[j];
            j++;
            k++;
            c = c+m-i;
        }
    }

    while(i<m)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while(j<n-m)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

int main()
{
    int t;

    cin>>t;
    while(t--)
    {
        int n;
        vector<int>A;

        cin>>n;
        int i,x;
        for(i=0;i!=n;i++)
        {
            cin>>x;
            A.push_back(x);
        }

        c = 0;
        mergeSort(A,n);     // define function

        cout<<c<<'\n';
    }

    return 0;
}
