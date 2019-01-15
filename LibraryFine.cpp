
// problem: "https://www.hackerrank.com/challenges/library-fine/problem"

#include<iostream>

using namespace std;

int main()
{
    int D[2],M[2],Y[2],n;
 
    n=-1;
    cin>>D[0]>>M[0]>>Y[0];
    cin>>D[1]>>M[1]>>Y[1];
    
    if(Y[0]<Y[1])
    {
        cout<<0;
        n=0;
    }
    else if(Y[0]==Y[1])
    {
        if(M[0]<M[1])
        {
            cout<<0;
            n=0;
        }
        
        else if(M[0]==M[1])
        {
            if(D[0]<=D[1])
            {   
                cout<<0;
                n=0;
            }
                        
        }
        
        else
            n=-1;
    }
    
    else
        n=-1;
    
    
  if(n!=0)  
  {
      if(Y[0]>Y[1])
        cout<<10000;
    
    else
    {
        if(M[0]>M[1])
            cout<<(M[0]-M[1])*500;
        else
            cout<<(D[0]-D[1])*15;
          
        
    }
  }  
    return 0;
}