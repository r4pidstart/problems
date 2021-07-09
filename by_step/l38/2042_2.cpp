// https://www.acmicpc.net/problem/2042
// 2021-07-10 03:34:39 280ms
#include<bits/stdc++.h>
using namespace std;

vector<long long> seg_tree, numbers;

long long seg_init(int now, int start, int end)
{
    if(start==end)
        return seg_tree[now]=numbers[start];
    return seg_tree[now]=(seg_init(now*2, start, (start+end)/2) + seg_init(now*2+1, (start+end)/2+1, end));
}

long long seg_get_sum(int now, int start, int end, int left, int right)
{
    if(right < start || end < left) // 구간 밖
        return 0;
    else if(left <= start && end <= right)
        return seg_tree[now];
    else
        return seg_get_sum(now*2, start, (start+end)/2, left, right)+seg_get_sum(now*2+1, (start+end)/2+1, end, left, right);
}

long long seg_update(int now, int start, int end, int index, long long target)
{
    if(!(start <= index && index <= end)) // 바꿀 필요 없으면
        return seg_tree[now];
    
    if(start==end) // 리프 노드이면
        return seg_tree[now]=target;

    return seg_tree[now]=(seg_update(now*2, start, (start+end)/2, index, target)+seg_update(now*2+1, (start+end)/2+1, end, index, target));
}

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    seg_tree=numbers=vector<long long>(4*n, 0);
    for(int i=0; i<n; i++)
        scanf("%lld", &numbers[i]);

    seg_init(1, 0, n-1);

    for(int i=0, l=m+k; i<l; i++)
    {
        long long a,b,c; scanf("%lld%lld%lld", &a,&b,&c);
        if(a==1)
            seg_update(1, 0, n-1, b-1, c);
        else
            printf("%lld\n", seg_get_sum(1, 0, n-1, b-1, c-1)); 
    }
}

/*
    update 방식을 diff를 이용하지 않고, 재귀를 이용하는 것으로 바꿈
*/
