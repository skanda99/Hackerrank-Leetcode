
// problem: "https://www.hackerrank.com/challenges/insertionsort1/problem"

#include<stdio.h>

int main()
{
    int n,a[1000],temp,x,i;

    scanf(" %d",&n);
    for(i=0; i<n;i++)
        scanf(" %d",&a[i]);

    temp=a[n-1];
    i=n-2;
    x=0;

    while(x!=-1&&i>=0)
    {
        if(temp<a[i])
            a[i+1]=a[i];

        else
        {
            a[i+1]=temp;
            x=-1;
        }

        for(int j=0;j<n;j++)
            printf("%d ",a[j]);

        printf("\n");
        //if(x==-1)
        //    break;

        i--;
    }

    if(a[0]>temp)
    {
        a[0]=temp;
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
    }
    return 0;
}
