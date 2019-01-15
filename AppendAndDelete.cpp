
// problem: "https://www.hackerrank.com/challenges/append-and-delete/problem"

#include<iostream>
#include<string.h>
#include<math.h>


using namespace std;

int main()
{
    char s[100],t[100];
    int i,j,k,ns,nt,d,n,ms,a;
    
    cin>>s;
    cin>>t;
    cin>>k;

    nt=strlen(t);
    ns=strlen(s);
    n=min(ns,nt);
    ms=-1;
    
    for(i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            ms=i;
            break;
        }
        
        
    }
    
    if(ms==0)
    {
        d=ns;
        a=nt;
        if(a+d<=k)
            cout<<"Yes";
        
        else
            cout<<"No";
    }
    
    else if(ms==-1)
    {
        if(nt>ns)
        {
            a=nt-ns;
            d=k-a;
            if(d%2==0)
                cout<<"Yes";
            else
                cout<<"No";
        }    
        
        else if(nt<ns)
        {
            d=ns-nt;
            a=k-d;
            if(a<nt)
            {
                if(a%2==0)
                    cout<<"Yes";
                else
                    cout<<"No";
            }
            else
            {
                if(a%2!=0)
                    cout<<"Yes";
                else
                    cout<<"No";
            }
              
        }    
        else
            cout<<"Yes";
        }
        
    else
    {
        d=ns-ms;
        a=nt-ms;
        if(((k-(a+d))%2==0)&&((k-(a+d))>=0))
            cout<<"Yes";
        else
            cout<<"No";
    }
    
    return 0;
       
}