
// problem: "https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char str[10000];
    int i,j,x,q,y;
    char word[15];

    strcpy(word,"hackerrank");

    cin>>q;

    for(i=0;i<q;i++)
    {
        cin>>str;
        x=0;
        y=-1;
        for(j=0;j<strlen(str);j++)
        {
            if(str[j]==word[x])
            {
                x++;
            }

            if(x==10)
            {
                y=0;
                break;
            }
        }

        if(y==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
