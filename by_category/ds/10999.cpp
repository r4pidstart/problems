// https://www.acmicpc.net/problem/10999
// 2021-09-17 02:33:51 268ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2

vector<long long> seg_tree, lazy, arr;

long long seg_init(int now, int s, int e)
{
    if(s==e) return seg_tree[now]=arr[s];
    return seg_tree[now]=seg_init(now*2, s, mid)+seg_init(now*2+1, mid+1, e);
}

void seg_lazy(int now, int s, int e)
{
    seg_tree[now*2]+=lazy[now]/(e-s+1)*(mid-s+1); // s ~ mid
    lazy[now*2]+=lazy[now]/(e-s+1)*(mid-s+1);
    seg_tree[now*2+1]+=lazy[now]/(e-s+1)*(e-mid); // mid+1 ~ e
    lazy[now*2+1]+=lazy[now]/(e-s+1)*(e-mid);
    lazy[now]=0;
}

long long seg_modify(int now, int s, int e, int l, int r, long long v)
{
    if(r<s || e<l) return seg_tree[now]; // 구간이 완전히 겹치지 않는 경우 수정할 필요 없음.
    if(l<=s && e<=r) // 구간이 완전히 포함되는 경우
    {
        lazy[now]+=v*(e-s+1);
        return seg_tree[now]+=v*(e-s+1);
    }
    seg_lazy(now, s, e);
    return seg_tree[now]=seg_modify(now*2, s, mid, l, r, v)+seg_modify(now*2+1, mid+1, e, l, r, v);
}

long long seg_sum(int now, int s, int e, int l, int r)
{
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return seg_tree[now];
    seg_lazy(now, s, e); // 다음 단계로 가기 전
    return seg_sum(now*2, s, mid, l, r)+seg_sum(now*2+1, mid+1, e, l, r);
}

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    seg_tree.assign(4*n, 0);
    lazy.assign(4*n, 0);
    arr.assign(n,0);
    
    for(int i=0; i<n; i++)
        scanf("%lld", &arr[i]);

    seg_init(1, 0, n-1);

    for(int i=0; i<m+k; i++)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd==1)
        {
            // modify
            int a,b; long long c; scanf("%d%d%lld", &a, &b, &c);
            seg_modify(1, 0, n-1, a-1, b-1, c);
        }
        else
        {
            // get sum
            int a,b; scanf("%d%d", &a, &b);
            printf("%lld\n", seg_sum(1, 0, n-1, a-1, b-1));
        }
    }
}

/*

*/