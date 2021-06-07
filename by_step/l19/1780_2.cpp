// https://www.acmicpc.net/problem/1780
// 2021-03-21 22:08:09 524ms
#include<iostream>
#include<vector>
using namespace std;

vector <vector <int>> arr(2187, vector<int>(2187,0)); // 3^7
int ans_0=0, ans_1=0, ans_m1=0;

int dc(int x, int y, int n)
{
    int flag=0, prev=arr[x][y];

    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
        {
            if(arr[i][j]!=prev)
            {
            flag++;
            break;
            }
        }
    
    if(flag==0)
    {
        if(prev==-1)
        {
            ans_m1++;
            return 0;
        }
        else if(prev==0)
        {
            ans_0++;
            return 0;
        }
        else if(prev==1)
        {
            ans_1++;
            return 0;
        }
    }
    else
    {
        dc(x,y,n/3); 
        dc(x,y+n/3,n/3); 
        dc(x,y+2*n/3,n/3); 

        dc(x+n/3,y,n/3);
        dc(x+n/3,y+n/3,n/3);
        dc(x+n/3,y+2*n/3,n/3);

        dc(x+2*n/3,y,n/3);
        dc(x+2*n/3,y+n/3,n/3);
        dc(x+2*n/3,y+2*n/3,n/3);
    }
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