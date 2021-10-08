// https://www.acmicpc.net/problem/12844
// 2021-09-19 21:48:06 792ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<int> seg_tree, seg_lazy, arr;

int seg_init(int now, int s, int e)
{
    if(s==e) return seg_tree[now]=arr[s];
    return seg_tree[now]=seg_init(now*2, s, mid)^seg_init(now*2+1, mid+1, e);
}

void seg_propagation(int now, int s, int e)
{
    if(seg_lazy[now])
    {
        seg_lazy[now*2]^=seg_lazy[now];
        seg_lazy[now*2+1]^=seg_lazy[now];
        seg_tree[now*2]^=(mid-s+1)&1 ? seg_lazy[now]:0;
        seg_tree[now*2+1]^=(e-mid)&1 ? seg_lazy[now]:0;
        seg_lazy[now]=0;
    }
}

int seg_get(int now, int s, int e, int l, int r)
{
    if(e<l || r<s) return 0; // k^0 = k
    if(l<=s && e<=r) return seg_tree[now];
    seg_propagation(now, s, e);
    return seg_get(now*2, s, mid, l, r)^seg_get(now*2+1, mid+1, e, l, r);
}

int seg_modify(int now, int s, int e, int l, int r, int v)
{
    if(e<l || r<s) return seg_tree[now];
    if(l<=s && e<=r)
    {
        seg_lazy[now]^=v;
        return seg_tree[now]^=(e-s+1)&1 ? v:0;
    }
    seg_propagation(now, s, e);
    return seg_tree[now]=seg_modify(now*2, s, mid, l, r, v)^seg_modify(now*2+1, mid+1, e, l, r, v);
}

int main(void)
{
    int n; scanf("%d", &n);
    seg_tree.assign(4*n, 0), seg_lazy.assign(4*n, 0), arr.assign(n, 0);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    seg_init(1, 0, n-1);
    
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd==1)
        {
            // modify
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            seg_modify(1, 0, n-1, a, b, c);
        }
        else
        {
            // get xor
            int a,b; scanf("%d%d", &a, &b);
            printf("%d\n", seg_get(1, 0, n-1, a, b));
        }
    }
}

/*
    
*/