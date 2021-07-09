// https://www.acmicpc.net/problem/11659
// 2021-07-10 00:39:35 64ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<int> sum(n+1, 0);
    // sum[i]: i번까지의 합
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        sum[i+1]=sum[i]+a;
    }

    while(m--)
    {
        int a, b; scanf("%d%d", &a,&b);
        printf("%d\n", sum[b]-sum[a-1]);
    }
}

/*

*/
