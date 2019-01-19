
// problem: "https://www.hackerrank.com/challenges/bigger-is-greater/problem"

#include<iostream>
#include<math.h>
#include<string.h>
#include<ctype.h>


using namespace std;

int main()
{
    long int i,j,k,t,n,l,num;
    char str[100],a[100],b[100],min,temp;
    
    
    cin>>t;
    
    for(i=0;i<t;i++)
    {
         
        cin>>str;
        
        l=strlen(str);
        n=-1;
        
        for(j=l-2;j>=0;j--)
        {
            if(str[j]<str[j+1])
            {
                n=j;
                break;
            }
        }
        
        if(n==-1)
        {
            cout<<"no answer"<<endl;
            continue;
        }
        
        if((n==0)&&(str[0]>str[1]))
        {
                                                   
            
            for(j=l-2;j>=0;j--)
            {
                if(str[j]!=str[j+1])
                    num=j;
            }
            
            temp=str[num];
            str[num]=str[num+1];
            str[num+1]=temp;
            
            for(j=0;j<l;j++)
                cout<<str[j];
            
            cout<<endl;
            
            continue;
            
        }
        
        min='}';
        for(j=n+1;j<l;j++)
            if((str[j]>str[n])&&(str[j]<min))
            {
                min=str[j];
                num=j;
            }
        
        temp=str[n];
        str[n]=str[num];
        str[num]=temp;
                
        for(j=0;j<=n;j++)
        {
            a[j]=str[j];
        }
        
        for(j=0;j<l-n-1;j++)
        {
            
            min='z';
            for(k=n+1;k<l;k++)
                if(isalpha(str[k]))
                    if(min>=str[k])
                    {
                        min=str[k];
                        num=k;
                    }
            
            b[j]=min;
            str[num]='_';
                                       
        }
        
        for(j=0;j<l-n-1;j++)
        {
            a[n+j+1]=b[j];
        }
        
        for(j=0;j<l;j++)
            cout<<a[j];
        
        cout<<endl;                                                
    }
    
    return 0;
}