
// problem: "https://www.hackerrank.com/challenges/alternating-characters/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char str[100000],ch;
    int i,j,t,count,tcount;

    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>str;

        ch=str[0];
        count=0;
        tcount=0;

        for(j=0;j<strlen(str);j++)
        {
            if(ch==str[j])
                count++;
            else
            {
                tcount=tcount+count-1;
                ch=str[j];
                count=1;
            }
        }

        tcount=tcount+count-1;

        cout<<tcount<<endl;
    }

    return 0;
}
