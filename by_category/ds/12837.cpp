// https://www.acmicpc.net/problem/12837
// 2021-09-11 00:56:47 100ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<long long> seg_tree;

long long seg_sum(int now, int s, int e, int l, int r)
{
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return seg_tree[now];
    return seg_sum(now*2, s, mid, l, r)+seg_sum(now*2+1, mid+1, e, l, r);
}

long long seg_update(int now, int s, int e, int t, int v)
{
    if(!(s<=t && t<=e)) return seg_tree[now];
    if(s==t && e==t) return seg_tree[now]+=v;
    return seg_tree[now]=seg_update(now*2, s, mid, t, v)+seg_update(now*2+1, mid+1, e, t, v);
}

int main(void)
{
    int n,q; scanf("%d%d", &n,&q);
    seg_tree.assign(4*n, 0);
    while(q--)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd==1)
        {
            int a,b; scanf("%d%d", &a,&b);
            seg_update(1, 0, n-1, a-1, b);
        }
        else
        {
            int a,b; scanf("%d%d", &a,&b);
            printf("%lld\n", seg_sum(1, 0, n-1, a-1, b-1));
        }
    }
}

/*

*/