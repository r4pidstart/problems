// https://www.acmicpc.net/problem/2740
// 2021-03-23 01:30:27 4ms
#include<iostream>
using namespace std;
int main(void)
{
    int a,b; scanf("%d%d", &a,&b);
    int arr_a[a][b];
    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            scanf("%d", &arr_a[i][j]);

    int c,d; scanf("%d%d", &c,&d);
    int arr_b[c][d];
    for(int i=0; i<c; i++)
        for(int j=0; j<d; j++)
            scanf("%d", &arr_b[i][j]);

    int result[a][d]={};
    for(int i=0; i<a; i++)
        for(int j=0; j<d; j++)
        {
            for(int k=0; k<b; k++)
                result[i][j]+=(arr_a[i][k]*arr_b[k][j]);
        }
    
    for(int i=0; i<a; i++)
    {  
        for(int j=0; j<d; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}   