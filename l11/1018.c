#include<stdio.h>

int main(void)
{
    int n,m;
    scanf("%d%d", &n,&m);
    char grid[n][m];
    for(int i=0; i<n; i++)
        scanf("%s", grid[i]);

    int a,b, min=32;
    for(int i=0; i<n-7; i++)
        for(int k=0; k<m-7; k++)
        {
            a=0, b=0;
            for(int l=k; l<k+8; l++)
                for(int j=i; j<i+8; j++)
                {
                    if(l%2==0)
                    {                    
                        if(j%2==0) 
                            if(grid[j][l]=='W')
                                a++;
                            else
                                b++;
                        else
                            if(grid[j][l]=='B')
                                a++;
                            else
                                b++;
                    }
                    else
                    {
                        if(j%2==0)
                            if(grid[j][l]=='B')
                                a++;
                            else
                                b++;
                        else
                            if(grid[j][l]=='W')
                                a++;
                            else
                                b++;
                    }
                }
            if(a<min)
                min=a;
            if(b<min)
                min=b;
        }
    printf("%d\n", min);
}
