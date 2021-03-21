// https://www.acmicpc.net/problem/1780
// 2021-03-21 22:01:59 572ms
#include<iostream>
#include<vector>
using namespace std;

vector <vector <int>> arr(2187, vector<int>(2187,0)); // 3^7
int ans_0=0, ans_1=0, ans_m1=0;

int dc(int x, int y, int n)
{
    int tmp[3]={}; // -1 0 1

    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
        {
            tmp[arr[i][j]+1]++;
        }
    
    if(tmp[0]==n*n)
    {
        ans_m1++;
        return 0;
    }
    else if(tmp[1]==n*n)
    {
        ans_0++;
        return 0;
    }
    else if(tmp[2]==n*n)
    {
        ans_1++;
        return 0;
    }
    
    dc(x,y,n/3); 
    dc(x,y+n/3,n/3); 
    dc(x,y+2*n/3,n/3); 

    dc(x+n/3,y,n/3);
    dc(x+n/3,y+n/3,n/3);
    dc(x+n/3,y+2*n/3,n/3);

    dc(x+2*n/3,y,n/3);
    dc(x+2*n/3,y+n/3,n/3);
    dc(x+2*n/3,y+2*n/3,n/3);

    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &arr[i][j]);
    dc(0,0,n);

    printf("%d\n%d\n%d", ans_m1, ans_0, ans_1);
}