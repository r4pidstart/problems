// https://www.acmicpc.net/problem/4256
// 2021-10-03 03:09:58 56ms
#include<bits/stdc++.h>
using namespace std;

vector<int> pre, in;

void post(int root, int lIn, int rIn)
{
    for(int i=lIn; i<=rIn; i++)
        if(pre[root]==in[i]) // 루트를 찾았다면,
        {
            // 좌 우로 재귀
            post(root+1, lIn, i-1);
            post(root+i-lIn+1, i+1, rIn);
            printf("%d ", pre[root]);
        }
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)    
    {
        int n; scanf("%d", &n);
        pre.assign(n,0), in.assign(n,0);
        for(int i=0; i<n; i++)
            scanf("%d", &pre[i]);
        for(int i=0; i<n; i++)
            scanf("%d", &in[i]);

        post(0, 0, n-1);
        printf("\n");
    }
}

/*
    
*/