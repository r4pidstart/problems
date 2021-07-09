// https://www.acmicpc.net/problem/2042
// 2021-07-10 03:24:06 264ms
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

void seg_update(int now, int start, int end, int index, long long diff)
{
    // 구간에 index가 포함되는 경우
    if(!(start <= index && index <= end))
        return;
    
    seg_tree[now]+=diff;
    // 끝 노드가 아니면
    if(start != end)
    {
        seg_update(now*2, start, (start+end)/2, index, diff);
        seg_update(now*2+1, (start+end)/2+1, end, index, diff);
    }
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
        {
            seg_update(1, 0, n-1, b-1, c-numbers[b-1]); // change numbers[b] to c
            numbers[b-1]=c;
        }
        else
            printf("%lld\n", seg_get_sum(1, 0, n-1, b-1, c-1)); 
    }
}

/*
    https://www.acmicpc.net/blog/view/9
*/
