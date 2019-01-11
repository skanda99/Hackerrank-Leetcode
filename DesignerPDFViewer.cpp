
// problem: "https://www.hackerrank.com/challenges/designer-pdf-viewer/problem"

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int height[26],i,max,j;
    char word[11],alpha[26],ch;
    
    for(i=0;i<26;i++)
        cin>>height[i];
    
    cin>>word;
    
    ch='a';
    
    for(i=0;i<26;i++)
        alpha[i]=ch+i;
    
    //for(i=0;i<26;i++)
    //    cout<<alpha[i]<<endl;
    max=0;
    
    for(i=0;word[i]!='\0';i++)
    {
        for(j=0;j<26;j++)
        {
            if(word[i]==alpha[j])
            {
                if(max<height[j])
                    max=height[j];
                
                break;
            }
        }
    }
    
    cout<<strlen(word)*max;
    
    return 0;   
}