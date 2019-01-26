
// problem: "https://www.hackerrank.com/challenges/happy-ladybugs/problem"

#include<iostream>
#include<ctype.h>

using namespace std;

int main()
{
    int g,i,j,u,k,t,c,n;
    char string[100],ch;
    
    
    cin>>g;
    
    for(i=0;i<g;i++)
    {
        cin>>n;
        cin>>string;
        
        t=u=0;
        
        for(j=0;j<n;j++)
            if(string[j]=='_')
                u++;
        
        if(u==0)
        {
           
            if(string[0]!=string[1])
            {
                cout<<"NO"<<endl;
                continue;
            }
            else if(string[n-2]!=string[n-1])
            {
                cout<<"NO"<<endl;
                continue;
            }
            else
            {
                for(j=1;j<n-1;j++)
                {
                    if((string[j]!=string[j-1])&&(string[j]!=string[j+1]))
                    {
                        cout<<"NO"<<endl;
                        u=-1;
                        break;
                    }
                }
                
                if(u==-1)
                    continue;
                else
                {
                    cout<<"YES"<<endl;
                    continue;
                }
            }
            
        }
        
        else   //u!=0
        {
            for(j=0;j<n;j++)
            {
                u=0;
                if(isalpha(string[j]))
                {
                    ch=string[j];
                    
                    for(k=j;k<n;k++)
                    {
                        if(ch==string[k])
                        {
                            u++;
                            string[k]='1';
                        }    
                    }
                    
                    if(u==1)
                    {
                        cout<<"NO"<<endl;
                        t=-1;
                        break;
                    }
                }                               
            }
            
            if(t==0)
                cout<<"YES"<<endl;
        }
            
        
        
        
    }
    
    
    return 0;
}