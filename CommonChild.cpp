
// problem: "https://www.hackerrank.com/challenges/common-child/problem"

#include<iostream>
#include<string.h>

using namespace std;

int arr[5005][5005];

int main()
{
    char s1[5000];
    char s2[5000];
    int i,j,size;

    cin >> s1;
    cin >> s2;

    //cout<<endl;
    //cout<<strlen(s1)<<"  "<<strlen(s2)<<endl;

    size=strlen(s1);

    for(i=0;i<=size;i++)
    {
        arr[i][0]=0;
        arr[0][i]=0;
    }

    for(i=1;i<=size;i++)
    {
        for(j=1;j<=size;j++)
        {
            if(s1[j-1]==s2[i-1])
                arr[i][j]=arr[i-1][j-1]+1;
            else
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    }

    cout<<arr[size][size];

    return 0;
}
