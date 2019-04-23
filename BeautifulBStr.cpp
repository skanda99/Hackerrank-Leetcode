
// problem: "https://www.hackerrank.com/challenges/beautiful-binary-string/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,j,count,size;
    char B[100];

    count=0;
    cin>>size;
    cin>>B;

    if(size<3)
    {
        if(B[0]!=B[1])
            count=0;
        else
            count=1;

    }

    else
    {
        for(i=2;i<size;i++)
      {
        if((B[i]=='0')&&(B[i-1]=='1')&&(B[i-2]=='0'))
        {
            B[i]='1';
            count++;
        }
      }
    }


    cout<<count;

    return 0;
}
