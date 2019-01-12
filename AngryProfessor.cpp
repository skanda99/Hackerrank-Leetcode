
// problem: "https://www.hackerrank.com/challenges/angry-professor/problem"

#include<iostream>

using namespace std;

int main()
{
    int T,timings,N,K,i,count;
    count=0;
    
    cin>>T;
    
    for(i=1;i<T+1;i++)
    {
        cin>>N>>K;
        for(int j=1;j<N+1;j++)
        {
            cin>>timings;
            if(timings<=0)
                count++;
        }
        
        if(count<K)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
       count=0; 
    }
    
    return 0;
}