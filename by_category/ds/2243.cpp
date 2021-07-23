// https://www.acmicpc.net/problem/2243
//  2021-07-24 00:47:54 300ms
#include<bits/stdc++.h>
using namespace std;

#define mid ((s+e)/2)
vector<int> seg_tree(4*1'000'000, 0), num(1'000'000, 0);

int seg_update(int now, int s, int e, int i, int t)
{
    if(!(s<=i && i<=e))
        return seg_tree[now];
    if(s==e)
        return seg_tree[now]=num[i]=t;
    return seg_tree[now]=seg_update(now*2, s, mid, i, t)+seg_update(now*2+1, mid+1, e, i, t);
}

int seg_sum(int now, int s, int e, int l, int r)
{
    if(r<s || e<l)
        return 0;
    if(l<=s && e<=r)
        return seg_tree[now];
    return seg_sum(now*2, s, mid, l, r)+seg_sum(now*2+1, mid+1, e, l, r);
}

void seg_find(int t)
{
    // find t th candy
    int l=0, h=999999, ans;
    while(l<=h)
    {
        int m=(l+h)/2;
        if(t <= seg_sum(1, 0, 999999, 0, m))
        {
            ans=m;
            h=m-1;
        }
        else
            l=m+1;
    }

    // get t th candy and print
    seg_update(1, 0, 999999, ans, num[ans]-1);
    printf("%d\n", ans+1);
}

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(a==1)
        {
            int b; scanf("%d", &b);
            seg_find(b);
        }
        else
        {
            int b,c; scanf("%d%d", &b, &c);
            seg_update(1, 0, 999999, b-1, num[b-1]+c);
        }
    }
}

/*

*/
