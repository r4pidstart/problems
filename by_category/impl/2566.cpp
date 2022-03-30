// https://www.acmicpc.net/problem/2566
// 2022-03-30 23:16:45 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int ans=-1, ansx, ansy;
    for(int i=0; i<9; i++) 
        for(int j=0; j<9; j++)
        {
            int a; scanf("%d", &a);
            if(a > ans)
                ans=a, ansx=j+1, ansy=i+1;
        }

    printf("%d\n%d %d", ans, ansy, ansx);
}

/*
    
*/