// https://www.acmicpc.net/problem/2502
// 2021-09-01 00:47:21 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int d,k; scanf("%d%d", &d,&k);
    for(int i=1; i<=k/2; i++)
    {
        vector<int> ans(31);
        int flag=0;
        ans[d]=k;
        ans[d-2]=i;
        ans[d-1]=k-i;

        int cur=d-3;
        while(cur!=0)
        {
            ans[cur]=ans[cur+2]-ans[cur+1];
            if(ans[cur] > ans[cur+1]) flag++;
            cur--;
        }
        if(!flag)
        {
            printf("%d\n%d", ans[1], ans[2]);
            return 0;
        }
    }
}

/*
    2 7 9 16 25 41
    10 21 31 52 83 135 218

    30 100,000

    1 99999
    2 99998
    ...
    49999 50001
    50000 50000

    2 26 28 54 82 136 218
*/