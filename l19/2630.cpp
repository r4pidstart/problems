// https://www.acmicpc.net/problem/2630
// 2021-03-21 21:33:20 0ms
#include<iostream>
#include<vector>
using namespace std;

vector <vector <int>> arr(128, vector<int>(128,0)); 
int res_w=0, res_b=0;

int dc(int x, int y, int n)
{
    int tmp=0;

    for(int i=x; i<x+n; i++) // whole square
        for(int j=y; j<y+n; j++)
            tmp+=arr[i][j];
    
    if(tmp==0)
    {        
        res_w++;
        return 0;
    }
    else if(tmp==n*n)
    {
        res_b++;
        return 0;
    }

    dc(x,y,n/2);
    dc(x+n/2,y,n/2);
    dc(x,y+n/2,n/2);
    dc(x+n/2,y+n/2,n/2);

    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &arr[i][j]);
    
    dc(0,0,n);

    printf("%d\n%d", res_w, res_b);
}