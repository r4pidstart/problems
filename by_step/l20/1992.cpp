// https://www.acmicpc.net/problem/1992
// 2021-03-21 21:47:45 0ms
#include<iostream>
#include<vector>
using namespace std;

vector <vector <char>> arr(64, vector<char>(64,0)); 

int dc(int x, int y, int n)
{
    int tmp=0;

    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            tmp+=arr[i][j]-'0';
    
    if(tmp==0)
    {
        printf("0");
        return 0;
    }
    else if(tmp==n*n)
    {
        printf("1");
        return 0;
    }
    printf("(");
    dc(x,y,n/2);
    dc(x,y+n/2,n/2);
    dc(x+n/2,y,n/2);
    dc(x+n/2,y+n/2,n/2);
    printf(")");

    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf(" %c", &arr[i][j]);
    dc(0,0,n);
}