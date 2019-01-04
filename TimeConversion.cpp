
// problem: "https://www.hackerrank.com/challenges/time-conversion/problem"

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    char ch[10];
    int n,i,j;
    
    cin>>ch;
    
    //00:00:00MM
    
    if(ch[8]=='A')
    {
        n=atoi(ch);
        if(n<12)
        for(int i=0;i<8;i++)
            cout<<ch[i];
        else
        {    
             cout<<0<<0;
             for(i=2;i<8;i++)
                 cout<<ch[i];
        } 
            
    }
    
    else
    {
             j=atoi(ch);
             if(j<12)
             {
                 cout<<j+12;
                 for(i=2;i<8;i++)
                 cout<<ch[i];
             }
                 else
             for(i=0;i<8;i++)
                 cout<<ch[i];

    }
    return 0;
}