#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int table1[10][10]={}, table2[9][9]={};
    int color=0;

    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            if((j%2==0 && i%2==color) || (j%2==1 && i%2==(!color)))
                table1[i][j]++;

        for(int i=0; i<10; i++)
        {
        for(int j=0; j<10; j++)
        printf("%d ", table1[i][j]);
        printf("\n");   
        }

    printf("\n");

        for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if((j%2==0 && i%2==color) || (j%2==1 && i%2==(!color)))
                table2[i][j]++;

        for(int i=0; i<9; i++)
        {
        for(int j=0; j<9; j++)
        printf("%d ", table2[i][j]);
        printf("\n");   
        }


}