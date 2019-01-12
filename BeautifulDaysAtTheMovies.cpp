
// problem: "https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem"

#include <iostream>

using namespace std;

long int reversed (long int n)
{
    long int m,r;
    m=n;
    r=0;
    
    while(m>=1)
    {
       r=(m%10)+r*10; 
       m=m/10;
    }
      
    return r;
}


int main() 
{
    long int i,j,k,count;
    cin>>i>>j>>k;
    
    count=0;
    
    for(int x=i;x<=j;x++)
    {
        if((x-reversed(x))%k==0)
            count++;
    }
    
    cout<<count;
    
    return 0;
}
