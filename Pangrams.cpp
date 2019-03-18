
// problem: "https://www.hackerrank.com/challenges/pangrams/problem"

#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
    char ch,str[1000];
    int i,j,x;

    cin.getline(str,1000);

    ch='a';

    j=0;

   // cout<<strlen(str)<<endl;

 //   for(i=0;i<strlen(str);i++)
       // cout<<str[i];

    while(1)
    {
        for(i=0;i<strlen(str);i++)
        {
            if(isalpha(str[i]))
            {
                x=0;
                if(ch==tolower(str[i]))
                {
                    ch++;
                    x=1;
                    break;
                }
            }
        }



        if(ch=='{')
        {
            j=0;
            break;
        }
        else if(x==0)
        {
            j=-1;
            break;
        }
    }

    if(j==0)
        cout<<"pangram"<<endl;
    else
        cout<<"not pangram"<<endl;

    //cout<<ch;
    return 0;
}
