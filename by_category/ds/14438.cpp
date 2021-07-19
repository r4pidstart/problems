// https://www.acmicpc.net/problem/14438
// 2021-07-20 06:05:19 84ms
#include<bits/stdc++.h>
using namespace std;

#define mid ((s+e)/2)
vector<int> num, seg;

int init(int now, int s, int e)
{
    if(s==e)
        return seg[now]=num[s];
    return seg[now]=min(init(now*2, s, mid), init(now*2+1, mid+1, e));
}

int update(int now, int s, int e, int i, int t)
{
    if(!(s<=i && i<=e))
        return seg[now];
    if(s==e)
        return seg[now]=t;
    return seg[now]=min(update(now*2, s, mid, i, t), update(now*2+1, mid+1, e, i, t));
}

int get_min(int now, int s, int e, int l, int r)
{
    if(r<s || e<l)
        return INT32_MAX;
    if(l<=s && e<=r)
        return seg[now];
    return min(get_min(now*2, s, mid, l, r), get_min(now*2+1, mid+1, e, l, r));
}

// int find(int now, int s, int e, int l, int r, int target)
// {
//     if(r<s || e<l)
//         return INT32_MAX;
//     if(s==e)
//         return seg[now]==target ? s:INT32_MAX;
//     return min(find(now*2, s, mid, l, r, target), find(now*2+1, mid+1, e, l, r, target));
// }

int main(void)
{
    int n; scanf("%d", &n);
    num.assign(n,0);
    seg.assign(4*n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);

    init(1, 0, n-1);
    
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        if(a==1)
            update(1, 0, n-1, b-1, c);
        else
            printf("%d\n", get_min(1, 0, n-1, b-1, c-1));

    }
}

/*

*/
