// https://www.acmicpc.net/problem/14428
// 2021-07-20 07:10:45 88ms 
#include<bits/stdc++.h>
using namespace std;

#define mid ((s+e)/2)
vector<int> num, seg;
int n; 

int init(int now, int s, int e)
{
    if(s==e)
        return seg[now]=s;
    int ret1=init(now*2, s, mid), ret2=init(now*2+1, mid+1, e);
    return seg[now]=num[ret1]<=num[ret2] ? ret1:ret2; // index of minimum value
}

int update(int now, int s, int e, int i, int t)
{
    if(!(s<=i && i<=e))
        return seg[now];
    if(s==e)
    {
        num[i]=t;
        return seg[now]=i;
    }
    int ret1=update(now*2, s, mid, i, t), ret2=update(now*2+1, mid+1, e, i, t);
    return seg[now]=num[ret1]<=num[ret2] ? ret1:ret2;
}

int get_min(int now, int s, int e, int l, int r)
{
    if(r<s || e<l)
        return n;
    if(l<=s && e<=r)
        return seg[now];
    int ret1=get_min(now*2, s, mid, l, r), ret2=get_min(now*2+1, mid+1, e, l, r);
    return num[ret1]<=num[ret2] ? ret1:ret2;
}

int main(void)
{
    scanf("%d", &n);
    num.assign(n+1,0);
    seg.assign(4*n,0);
    num[n]=INT32_MAX;
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
            printf("%d\n", get_min(1, 0, n-1, b-1, c-1)+1);
    }
}

/*

*/
