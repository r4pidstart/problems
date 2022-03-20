// https://www.acmicpc.net/problem/1004
// 2022-03-20 17:47:31 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int sx, sy, ex, ey; scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        int n; scanf("%d", &n);
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            int a,b,r; scanf("%d%d%d", &a, &b, &r);

            if(r*r > (sx-a)*(sx-a)+(sy-b)*(sy-b) and r*r > (ex-a)*(ex-a)+(ey-b)*(ey-b)) continue;
            else if(r*r > (sx-a)*(sx-a)+(sy-b)*(sy-b)) cnt++;
            else if(r*r > (ex-a)*(ex-a)+(ey-b)*(ey-b)) cnt++;
        }
        printf("%d\n", cnt);
    }
}

/*
    
*/