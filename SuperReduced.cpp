
// problem: "https://www.hackerrank.com/challenges/reduced-string/problem"

#include<iostream>
#include<string.h>
#include<ctype.h>
#include<string>

using namespace std;

int main()
{
    int count=0;
    int i,j,x,y;
    char ch,str1[101],str2[101],str3[101];

    cin>>str1;


    x=strlen(str1);
    while(1)
    {

    ch=str1[0];
    j=0;
    count=0;

    for(i=0;i<x;i++)
        str3[i]=str1[i];

    y=x;

    for(i=0;i<x;i++)
    {
        if(ch==str1[i])
            count++;
        else
        {
            if(count%2!=0)
            {
                str2[j]=ch;
                j++;
            }
            ch=str1[i];
            count=1;
        }
    }

    if(count%2!=0)
    {
        str2[j]=ch;
        j++;
    }

    for(i=0;i<strlen(str2);i++)
        str1[i]=str2[i];

    x=j;

    if(x==y)
        break;

    }

    if(x==0)
        cout<<"Empty String"<<endl;
    else
        for(i=0;i<x;i++)
            if(isalpha(str1[i]))
            cout<<str1[i];


    return 0;
}
