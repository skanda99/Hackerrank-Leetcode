
// problem: "https://www.hackerrank.com/challenges/two-pluses/problem"

#include<iostream>
#include<vector>

using namespace std;


int checkMax(vector<vector<char>>G,int n,int m)
{
    int l = 0;
    int i,j;
    for(i=0;i!=n;i++)
    {
        for(j=0;j!=m;j++)
        {
            if(G[i][j]=='G')
            {
                int k=0;
                while(1)
                {
                    if(i-k>=0 && i+k<n && j-k>=0 && j+k<m)
                    {
                        if(G[i-k][j] == 'G' && G[i+k][j] == 'G' &&
                          G[i][j-k] == 'G' && G[i][j+k] == 'G')
                            k++;
                        else    
                            break;
                    }
                    else    
                        break;
                    
                }
                l = max(l,k);
            }
        }
    }

    return 4*l-3;
}

int MaxArea(vector<vector<char>>&G,int n,int m)
{
    vector<vector<char>>Gcopy(G);
    int i,j;
    int a,b,A;
    A = 0;

    for(i=0;i!=n;i++)
    {
        for(j=0;j!=m;j++)
        {
            vector<vector<char>> Gcopy(G);
            if(Gcopy[i][j]=='G')
            {
                int k=0;
                while(1)
                {
                    if(i-k>=0 && i+k<n && j-k>=0 && j+k<m)
                    {
                      if (Gcopy[i-k][j] == 'G' && Gcopy[i+k][j] == 'G' &&
                          Gcopy[i][j-k] == 'G' && Gcopy[i][j+k] == 'G')
                          {
                            Gcopy[i-k][j] = Gcopy[i+k][j] = Gcopy[i][j-k] = Gcopy[i][j+k] = 'B';
                            a = 4*(k+1)-3;
                            b = checkMax(Gcopy,n,m);    // define function
                            A = max(A,a*b);
                          }
                          else
                            break;
                    }
                    else
                        break;

                    k++;
                }
            }
        }
    }

    return A;
}

int main() 
{
  int n, m;

  cin >> n >> m;
  vector<vector<char>> G(n, vector<char>(m));
  int i, j;

  for (i = 0; i != n; i++)
    for (j = 0; j != m; j++)
      cin >> G[i][j];

  cout << MaxArea(G, n, m); // define func

  return 0;
}