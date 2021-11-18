// https://www.acmicpc.net/problem/23348
// 2021-11-19 00:06:37 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int A,B,C; scanf("%d%d%d", &A,&B,&C);
    int n; scanf("%d", &n);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int tmp=0;
        for(int j=0; j<3; j++)
        {
            int a,b,c; scanf("%d%d%d", &a,&b,&c);
            tmp+=a*A+b*B+c*C;
        }
        ans=max(ans, tmp);
    }
    printf("%d", ans);
}

/*
    3*1 + 6*2 + 9*3 = 42
    3*1 + 6*1 + 9*1 = 18
    3*2 + 6*2 + 9*2 = 36
*/