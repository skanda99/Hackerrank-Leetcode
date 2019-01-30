
// problem: "https://www.hackerrank.com/challenges/almost-sorted/problem"

#include<iostream>

using namespace std;

long long int check_sort (long long int array[100000],long long int n,long long int z)
{
    int i;
    if(z<0)
        z=z+1;
    
    for(i=z;i<n-1;i++)
    {
        if(array[i]>array[i+1])
        {
            return i;
        }
    }
    
    return -1;
}
int main()
{
    long long int A[100000],i,j,x,y,n,z,temp;
    
    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];
    
    x=check_sort(A,n,0);
    
    if((x==-1)||(n==2))
    {
        if(x==-1)
            cout<<"yes"<<endl;
        else
        {
            cout<<"yes"<<endl;
            cout<<"swap "<<1<<" "<<2<<endl;
        }
    }
    
    else if(x+1<n-1)
    {
        if(A[x+1]<A[x+2])
        {
            y=-1;
            for(i=x+1;i<n-1;i++)
            {
                if(A[i]>A[i+1])
                {
                    y=i+1;
                    break;
                }
            }
            
            if(y!=-1)
            {
                temp=A[x];
                A[x]=A[y];
                A[y]=temp;
                
                z=check_sort(A,n,x-1);
                if(z==-1)
                {
                    cout<<"yes"<<endl;
                    cout<<"swap "<<x+1<<" "<<y+1<<endl;
                }
                else
                {
                    cout<<"no"<<endl;
                }
            }
            else
            {
                temp=A[x];
                A[x]=A[x+1];
                A[x+1]=temp;
                
                z=check_sort(A,n,x-1);
                if(z==-1)
                {
                    cout<<"yes"<<endl;
                    cout<<"swap "<<x+1<<" "<<x+2<<endl;
                }
                else
                {
                    cout<<"no"<<endl;
                }
            }
        }
        else
        {
            y=-1;
            for(i=x+1;i<n-1;i++)
                if(A[i]<A[i+1])
                {
                    y=i;
                    break;
                }
            
            if(y!=-1)
            {
               
                
                if((A[x-1]<A[y])&&(A[x]<A[y+1])&&(x>0))
                {
                    z=check_sort(A,n,y+1);
                    if(z==-1)
                    {
                         cout<<"yes"<<endl;
                         cout<<"reverse "<<x+1<<" "<<y+1<<endl;
                    }
                    else
                    {
                         cout<<"no"<<endl;
                    }
                }
                else if((A[x]<A[y+1]))
                {
                    z=check_sort(A,n,y+1);
                    if(z==-1)
                    {
                         cout<<"yes"<<endl;
                         cout<<"reverse "<<x+1<<" "<<y+1<<endl;
                    }
                    else
                    {
                         cout<<"no"<<endl;
                    }
                }
                else
                    
                    cout<<"no"<<endl;
            }
            else
            {
                if((A[n-1]>A[x-1])&&(x>0))
                {
                    cout<<"yes"<<endl;
                    cout<<"reverse "<<x+1<<" "<<n<<endl;
                }
                else if(x==0)
                {
                    cout<<"yes"<<endl;
                    cout<<"reverse "<<x+1<<" "<<n<<endl;
                }
                else
                    cout<<"no"<<endl;
            }
             
        }
    }
    
    else
    {
        if(A[x-1]<A[x+1])
        {
            cout<<"yes"<<endl;
            cout<<"swap "<<x+1<<" "<<x+2<<endl;
        }
        else
            cout<<"no"<<endl;

    }
    
    
    return 0;
    
}
    