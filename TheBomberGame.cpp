
// problem: "https://www.hackerrank.com/challenges/bomber-man/problem"

#include<iostream>

using namespace std;

char grid_O[201][201],grid_Z[201][201],grid_T[201][201],grid_R[201][201];
int R,C;
long long int N;



void isolated (char grid_i[201][201],char grid_o[201][201])
{
    int i,j;
    
    if((R==1)&&(C!=1))
    {
        i=R-1;
        for(j=1;j<C-1;j++)
        {
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i][j+1]=='.')&&(grid_i[i][j-1]=='.'))
                    grid_o[i][j]='O';
        
            else
                grid_o[i][j]='.';
        }
        
        i=0; j=0;
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if(grid_i[i][j+1]=='.')
                    grid_o[i][j]='O';
    
            else
                grid_o[i][j]='.';
        
        i=0; j=C-1;
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if(grid_i[i][j-1]=='.')
                    grid_o[i][j]='O';
    
            else
                grid_o[i][j]='.';
        
        
        return;
    }
    
    else if((R!=1)&&(C==1))
    {
        j=C-1;
        for(i=1;i<R-1;i++)
        {
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i+1][j]=='.')&&(grid_i[i-1][j]=='.'))
                    grid_o[i][j]='O';
        
            else
                grid_o[i][j]='.';
        }
        
        i=0; j=0;
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if(grid_i[i+1][j]=='.')
                    grid_o[i][j]='O';
    
            else
                grid_o[i][j]='.';
        
        i=R-1; j=0;
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if(grid_i[i-1][j]=='.')
                    grid_o[i][j]='O';
    
            else
                grid_o[i][j]='.';
        
        
        return;
    }
    
    
    
    for(i=1;i<R-1;i++)
        for(j=1;j<C-1;j++)
        {
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i][j+1]=='.')&&(grid_i[i][j-1]=='.')&&(grid_i[i+1][j]=='.')&&(grid_i[i-1][j]=='.'))
                    grid_o[i][j]='O';   
            
            else
                grid_o[i][j]='.';
        }
    
    i=0;
    for(j=1;j<C-1;j++)
    {
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i][j+1]=='.')&&(grid_i[i][j-1]=='.')&&(grid_i[i+1][j]=='.'))
                    grid_o[i][j]='O';
        
            else
                grid_o[i][j]='.';
    }
    
    i=R-1;
    for(j=1;j<C-1;j++)
    {
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i][j+1]=='.')&&(grid_i[i][j-1]=='.')&&(grid_i[i-1][j]=='.'))
                    grid_o[i][j]='O';
        
            else
                grid_o[i][j]='.';
    }
    
    j=0;
    for(i=1;i<R-1;i++)
    {
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i][j+1]=='.')&&(grid_i[i+1][j]=='.')&&(grid_i[i-1][j]=='.'))
                    grid_o[i][j]='O';
        
            else
                grid_o[i][j]='.';
    }
    
    j=C-1;
    for(i=1;i<R-1;i++)
    {
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i][j-1]=='.')&&(grid_i[i+1][j]=='.')&&(grid_i[i-1][j]=='.'))
                    grid_o[i][j]='O';
        
            else
                grid_o[i][j]='.';
    }
    
    i=0; j=0;
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i][j+1]=='.')&&(grid_i[i+1][j]=='.'))
                    grid_o[i][j]='O';
    
            else
                grid_o[i][j]='.';
    
    i=R-1; j=0;
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i][j+1]=='.')&&(grid_i[i-1][j]=='.'))
                    grid_o[i][j]='O';
    
            else
                grid_o[i][j]='.';
    
    i=0; j=C-1;
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i][j-1]=='.')&&(grid_i[i+1][j]=='.'))
                    grid_o[i][j]='O';
    
            else
                grid_o[i][j]='.';
    i=R-1; j=C-1;
            if(grid_i[i][j]=='O')
                grid_o[i][j]='.';
            
            else            
                if((grid_i[i][j-1]=='.')&&(grid_i[i-1][j]=='.'))
                    grid_o[i][j]='O';
    
            else
                grid_o[i][j]='.';
}


int main()
{
    int i,j;
    
    cin>>R>>C>>N;
    
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            cin>>grid_O[i][j];
    
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            grid_Z[i][j]='O';
    
    if(N==1)
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
              cout<<grid_O[i][j];
            
            cout<<endl;
        }
    
    else if(N%2==0)
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
              cout<<grid_Z[i][j];
            
            cout<<endl;
        }
    
    else if((N-3)%4==0)
    {
        isolated(grid_O,grid_T);
        
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
              cout<<grid_T[i][j];
            
            cout<<endl;
        }
    }
    
    else
    {
        isolated(grid_O,grid_T);
        isolated(grid_T,grid_R);
        
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
              cout<<grid_R[i][j];
            
            cout<<endl;
        }
    }
    
    
    return 0;        
}