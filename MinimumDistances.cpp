
// problem: "https://www.hackerrank.com/challenges/minimum-distances/problem"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    long int min,n,i,j,d[1000],a[1000],count;
    
    
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    count=0;
    
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                d[count]=abs(i-j);
                count++;
                break;
            }
        }    
    }
    
    
    
    min=d[0];
    
    for(i=0;i<count;i++)
    {
        if(min>d[i])
            min=d[i];
    } 
    
    if(count==0)
        cout<<-1;
    
    else
        cout<<min;
    
    return 0;
}