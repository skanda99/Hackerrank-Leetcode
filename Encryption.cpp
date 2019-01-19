
// problem: "https://www.hackerrank.com/challenges/encryption/problem"

#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

int main()
{
    char string[81];
    int i,j,l,r,c;
    
    cin>>string;
    
    l=strlen(string);
    r=floor(pow(l,0.5));
    if(l==(r*r))
        c=r;
    else
        c=r+1;
    
    for(i=0;i<c;i++)
    {
        for(j=i;j<l;j=j+c)
            cout<<string[j];
        
        cout<<" ";
    }
    
    return 0;
}
