// https://www.acmicpc.net/problem/1275
// 2021-07-16 01:10:14 164ms
#include<bits/stdc++.h>
using namespace std;

#define mid ((s+e)/2)
vector<long long> numbers, seg_tree;

long long seg_init(int now, int s, int e)
{
    if(s==e)
        return seg_tree[now]=numbers[s];
    return seg_tree[now]=seg_init(now*2, s, mid)+seg_init(now*2+1, mid+1, e);
}

long long seg_update(int now, int s, int e, int i, int t)
{
    if(!(s<=i && i<=e))
        return seg_tree[now];
    if(s==e)
        return seg_tree[now]=t;
    return seg_tree[now]=seg_update(now*2, s, mid, i, t)+seg_update(now*2+1, mid+1, e, i, t);
}

long long seg_sum(int now, int s, int e, int l, int r)
{
    if(r < s || e < l)
        return 0;
    if(l<=s && e<=r)
        return seg_tree[now];
    return seg_sum(now*2, s, mid, l, r)+seg_sum(now*2+1, mid+1, e, l, r);
}

int main(void)
{
    int n, q; scanf("%d%d", &n,&q);
    numbers.assign(n, 0), seg_tree.assign(4*n, 0);
    for(int i=0; i<n; i++)
        scanf("%lld", &numbers[i]);
        
    seg_init(1, 0, n-1);

    for(int i=0; i<q; i++)
    {
        int a,b,c,d; scanf("%d%d%d%d", &a,&b,&c,&d);
        printf("%lld\n", a<b ? seg_sum(1,0,n-1,a-1,b-1):seg_sum(1,0,n-1,b-1,a-1));
        seg_update(1, 0, n-1, c-1, d);
    }
}

/*

*/
