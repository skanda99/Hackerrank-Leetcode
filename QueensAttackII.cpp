
// problem: "https://www.hackerrank.com/challenges/queens-attack-2/problem"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    long unsigned int rq,cq,n,k,n1,n2,n3,n4,n5,n6,n7,n8,i,r,c;
    
    
    cin>>n>>k;
    
    cin>>rq>>cq;
    
    n1=n-cq;
    n3=n-rq;
    n5=cq-1;
    n7=rq-1;
    
    n2=min(n1,n3);
    n4=min(n3,n5);
    n6=min(n5,n7);
    n8=min(n7,n1);
    
    
    for(i=0;i<k;i++)
    {   
        cin>>r>>c;
        if(r==rq)
        {
            if(c>cq)
            {
                if(n1>(c-cq-1))
                    n1=c-cq-1;
            }
        
            else
            {
                if(n5>(cq-c-1))
                    n5=cq-c-1;
            }
        }    
        
        else if(c==cq)
        {
            if(r>rq)
            {
                if(n3>(r-rq-1))
                    n3=r-rq-1;
            }
            
            else
            {    
                if(n7>(rq-r-1))
                    n7=rq-r-1;
            }
        }    
        
        else if((r-c)==(rq-cq))
        {
            if(c>cq)
            {    
                if(n2>(c-cq-1))
                    n2=c-cq-1;
            }
            
            else
            {
                if(n6>(cq-c-1))
                    n6=cq-c-1;
            }
        }
        
        else if((r+c)==(rq+cq))
        {
            if(c>cq)
            {
                if(n8>(c-cq-1))
                    n8=c-cq-1;
            }
            else
            {
                if(n4>(cq-c-1))
                    n4=cq-c-1;
            }
        }
        
        else
            continue;
    }
    
    
    cout<<n1+n2+n3+n4+n5+n6+n7+n8;
    
    return 0;
}