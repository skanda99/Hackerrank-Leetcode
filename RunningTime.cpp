
// problem: "https://www.hackerrank.com/challenges/runningtime/problem"

#include<iostream>

using namespace std;

int main()
{
    int a[1002],n,i,j,temp,count;

    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    count=0;

    for(i=1;i<n;i++)
    {
        j=i;
        while(a[j]<a[j-1]&&j!=0)
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;
            count++;
        }
    }

    cout<<count;

    return 0;
}
