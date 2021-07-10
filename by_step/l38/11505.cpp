// https://www.acmicpc.net/problem/11505
// 2021-07-11 04:47:27 220ms
#include<bits/stdc++.h>
using namespace std;

#define mid ((start+end)/2)
#define MAX 1'000'000'007

vector<long long> seg_tree, numbers;

long long seg_init(int now, int start, int end)
{
    if(start==end)
        return seg_tree[now]=numbers[start];
    return seg_tree[now]=(seg_init(now*2, start, mid)*seg_init(now*2+1, mid+1, end)%MAX);
}

long long seg_get_mul(int now, int start, int end, int left, int right)
{
    if(right < start || end < left) 
        return 1;
    else if(left <= start && end <= right)
        return seg_tree[now];
    else
        return seg_get_mul(now*2, start, mid, left, right)*seg_get_mul(now*2+1, mid+1, end, left, right)%MAX;
}

long long seg_update(int now, int start, int end, int index, int target)
{
    if(index < start || end < index)
        return seg_tree[now];
    else if(start==end)
        return seg_tree[now]=target;
    else
        return seg_tree[now]=(seg_update(now*2, start, mid, index, target)*seg_update(now*2+1, mid+1, end, index, target)%MAX);
}

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    numbers.assign(n, 0);
    seg_tree.assign(4*n, 0);
    for(int i=0; i<n; i++)
        scanf("%lld", &numbers[i]);

    seg_init(1, 0, n-1);
    for(int i=0, l=m+k; i<l; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        if(a==1)
            seg_update(1, 0, n-1, b-1, c);
        else
            printf("%lld\n", seg_get_mul(1, 0, n-1, b-1, c-1));
    }
}

/*

*/
