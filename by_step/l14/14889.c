#include<stdio.h>
#include<stdlib.h>

int n;
int stat[21][21];
int *teamA, *teamB, *sel;
int min=1000;

int calculate(void)
{
    int tmpA=0, tmpB=0;
    for(int i=0; i<n/2; i++)
        for(int j=i; j<n/2; j++)
        {
            tmpA+=stat[teamA[i]][teamA[j]];
            tmpA+=stat[teamA[j]][teamA[i]];
            tmpB+=stat[teamB[i]][teamB[j]];
            tmpB+=stat[teamB[j]][teamB[i]];
        }

    if(min>abs(tmpA-tmpB))
        min=abs(tmpA-tmpB);
    // free(teamB); ???????        
    teamB=malloc(2*n+1);

}

int appand(int i)
{
    int N=0;
    while(teamB[N]!=0)
        N++;
    teamB[N]=i;
}

int sort(void)
{
    for(int i=1; i<n+1; i++)
        if(sel[i]==0)
            appand(i);
    calculate();
}

int dfs1(int index, int k)
{
    if(index==n/2 && teamA[index-1]!=0)
    {
        sort();
    }
    else
        for(int i=k+1; i<n; i++)
        {
            sel[i]=1;
            teamA[index]=i;
            dfs1(index+1, i);
            sel[i]=0;
            teamA[index]=0;
        }
}

int main(void)
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &stat[i+1][j+1]);

    sel=malloc(4*n+1);
    teamA=malloc(2*n+1), teamB=malloc(2*n+1);
    
    dfs1(0,0);

    printf("%d", min);

    // free(sel);
    // free(teamA);
}