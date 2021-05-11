// https://www.acmicpc.net/problem/9372
// 2021-05-11 21:36:52 32ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t,n,m,t1,t2; scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n,&m);
        for(int i=0; i<m; i++)
            scanf("%d%d", &t1,&t2);
        printf("%d\n", n-1);
    }
}