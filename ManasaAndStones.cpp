
// problem: "https://www.hackerrank.com/challenges/manasa-and-stones/problem"

#include<iostream>

using namespace std;

int main()
{
    int n,i,j,T,a,b,min,max;
    long long int sum;
    
    sum=0;
    
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>n>>a>>b;
        
        if(a>b)
        {
            max=a;
            min=b;
        }
        else
        {
            max=b;
            min=a;
        }
        
        if(max>min)
            for(j=0;j<n;j++)
            {
                sum=(j*max)+((n-1-j)*min);
                cout<<sum<<" ";
            }
        
        else
            cout<<(n-1)*min;
        
        cout<<endl;
    }
    
    return 0;
}