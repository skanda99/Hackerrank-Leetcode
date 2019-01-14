
// problem: "https://www.hackerrank.com/challenges/extra-long-factorials/problem"

#include<iostream>

using namespace std;

int main()
{
    int N[201],carry,x,i,w,y;
    
    cin>>y;
    
    
    for(i=0;i<201;i++)
        N[i]=0;
   
    N[0]=1;
   
    
    for(int j=1;j<=y;j++)         
  {   
    carry=0;
    
    for(i=0;i<201;i++)
    {
        x=(N[i]*j)+carry;
        N[i]=x%10;
        carry=x/10;
    
    }
        
    
    //for(i=n;i>=0;i--)
      //  cout<<N[i];
  }  
    
    for(i=200;i>=0;i--)
    {
        if(N[i]>0)
        {
            w=i;
            break;
        }
    }
    
    for(i=w;i>=0;i--)
        cout<<N[i];
    
    return 0;
}