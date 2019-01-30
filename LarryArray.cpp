
// problem: "https://www.hackerrank.com/challenges/larrys-array/problem"

#include<iostream>

using namespace std;

int check (int array[1000],int size,int x)                 //x is last sorted number
{
    int i;
    
       
    for(i=x;i<size;i++)
    {
        if(array[i]!=i+1)
            return i+1;                                    //i+1=y   returning number which has to be sorted next
    }
    
    return 0;                                              // completely sorted
}

int position (int array[1000],int size,int x,int y)        //y is number to be sorted next
{
    int i;
    for(i=x;i<size;i++)
    {
        if(array[i]==y)
            break;                                      //z=i   returning index of number to be sorted
    }
    
    return i;
}

void move (int array[1000],int x,int z,int y)                     //z is the index of the number to be sorted 
{
    int m,temp;
    
    while(array[x]!=y)
    {
        
    m=z-x;
    
    if(m==1)
    {
        temp=array[z-1];
        array[z-1]=array[z];
        array[z]=array[z+1];
        array[z+1]=temp;
        z=z-1;
    }
    else
    {
        temp=array[z-2];
        array[z-2]=array[z];
        array[z]=array[z-1];
        array[z-1]=temp;
        z=z-2;
    }
    }    
}

int main()
{
    int A[1000],N,T,i,j,y,x,z;
    
    cin>>T;
    for(i=0;i<T;i++)
    {
        x=-1;
        cin>>N;
        for(j=0;j<N;j++)
        {
            cin>>A[j];
            if(x==-1)
            {
                if(j+1!=A[j])
                    x=j;
            }
        }
        
        
        while(1)
        {
            y=check(A,N,x);
            if(y==0)
            {
                cout<<"YES"<<endl;
                break;
            }
            else if(y==N-1)
            {
                cout<<"NO"<<endl;
                break;
            }
            else
            {
                z=position(A,N,x,y);
                move(A,x,z,y);
                for(j=x;j<N;j++)
                {
                    if(A[j]!=j+1)
                    {
                        x=j;
                        break;
                    }
                }
            }
        }
            
        
        
    }
    
    return 0;
}