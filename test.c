#include<stdio.h>

int arr[16][16];
int N=0;

int pactorial(int n)
{
    int res=1;
    for(int i=1; i<n+1; i++)
        res*=i;
    return res;
}

int combination(int n, int r)
{
    return pactorial(n)/pactorial(n-r)/pactorial(r);
}
// test
int queen(int x, int y, int n)
{
    if (x==n && y==n)
    {
        int Q=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(arr[i][j]==-1)
                    Q++;
        
        if (Q>N)
            {
                if (Q=n)
                {
                    N++;
                    return 0;
                }
                N+=combination(Q,n);
            }
    }
    for(int i=x; i<n+1; i++)
        for(int j=y; j<n+1; j++)
        {
            if(arr[i][j]<i+j)
            {
                arr[i][j]=i+j;5
                queen(i,j,n); // X

                arr[i][j]=-1;
                for(int k=0; k<n+1; k++)
                    arr[k][j]=i+j;
                for(int l=0; l<n+1; l++)
                    arr[i][l]=i+j;
                for(int a=i, b=j; a!=n && b!=n; a++,b++)
                    arr[a][b]=i+j;
                for(int a=i, b=j; a!=0 && b!=0; a--,b--)
                    arr[a][b]=i+j;
                queen(i,j,n); // O
            }
        }

int main(void)
{
    int n;
    scanf("%d", &n);
    queen(0,0,n);
    printf("%d", N);
}
