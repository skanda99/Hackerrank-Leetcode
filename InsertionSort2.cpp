
// problem: "https://www.hackerrank.com/challenges/insertionsort2/problem"

#include<stdio.h>

int main()
{
    int s,a[1000],i,j,temp;

    scanf(" %d",&s);
    for(i=0;i<s;i++)
        scanf(" %d",&a[i]);

    for(i=1;i<s;i++)
    {
        j=i-1;

        while(j>=0)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
            else
                break;

            j--;
        }

        for(int k=0;k<s;k++)
            printf("%d ",a[k]);

        printf("\n");
    }

    return 0;
}
