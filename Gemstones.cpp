
// problem: "https://www.hackerrank.com/challenges/gem-stones/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int alpha[100][26],i,j,N,count,c;

    char str[100];

    cin>>N;

    for(i=0;i<N;i++)
        for(j=0;j<26;j++)
            alpha[i][j]=0;

    for(i=0;i<N;i++)
    {
        cin>>str;

        for(j=0;j<strlen(str);j++)
        {
            alpha[i][(int)(str[j])-97]++;
        }
    }

    count=0;
    for(j=0;j<26;j++)
    {
        c=-1;
        for(i=0;i<N;i++)
            if(alpha[i][j]==0)
            {
                c=0;
                break;
            }

        if(c==-1)
            count++;
    }

    cout<<count;

    return 0;
}
