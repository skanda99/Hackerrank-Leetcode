
// problem: "https://www.hackerrank.com/challenges/cut-the-sticks/problem"

#include<iostream>

using namespace std;

int main()
{
    int A[1000],n,min,t,count,i,s;
    
    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];
    
    min=A[0];
    
    for(i=0;i<n;i++)
        if(min>A[i])
            min=A[i];
    
    i=0;
    t=min;
    count=0;
    s=0;
    
    cout<<n<<endl;
    
    while(1)
    {
        A[i]=A[i]-t;
        
        if(s==0)
        {
            if(A[i]>0)
            {
                min=A[i];
                s=-1;
            }
        }
        
        if(A[i]>0)
        {
            count++;
            if(min>A[i])
                min=A[i];
        }
        i++;
        
        if(i==n)
        {
            if(count==0)
                break;
            
            cout<<count<<endl;
            
            t=min;
            count=0;
            i=0;
            s=0;
        }
    }
    
    return 0;
}