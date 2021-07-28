// https://www.acmicpc.net/problem/16975
// 2021-07-29 05:08:17 108ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<int> num(100000);
vector<long long> seg_tree(400000);
// 100,000*1,000,000 > int

void seg_init(int now, int s, int e)
{
    if(s==e)
        seg_tree[now]=num[s];
    else
        seg_init(now*2, s, mid), seg_init(now*2+1, mid+1, e);
}

void seg_update(int now, int s, int e, int l, int r, int t)
{
    if(r<s || e<l) // 겹치지 않는 경우 
        return;
    else if(l<=s && e<=r) // 바꿀 구간이 해당 구간을 완전히 포함하는경우
        seg_tree[now]+=t;
    else
        seg_update(now*2, s, mid, l, r, t), seg_update(now*2+1, mid+1, e, l, r, t); 
}

long long seg_getx(int now, int s, int e, int x)
{
    if(!(s<=x && x<=e))
        return 0;
    else if(s==e)
        return seg_tree[now];
    else
        return seg_getx(now*2, s, mid, x)+seg_getx(now*2+1, mid+1, e, x)+seg_tree[now];
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);

    seg_init(1, 0, n-1);

    int m; scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd==1)
        {
            int a,b,c; scanf("%d%d%d", &a,&b,&c);
            seg_update(1, 0, n-1, a-1, b-1, c);
        }
        else
        {
            int x; scanf("%d", &x);
            printf("%lld\n", seg_getx(1, 0, n-1, x-1));
        }
    }
}

/*

*/
