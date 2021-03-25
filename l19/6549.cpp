// https://www.acmicpc.net/problem/6549
// 2021-03-26 01:21:39 120ms
// https://yabmoons.tistory.com/598
#include<iostream>
#include<vector>
using namespace std;
#define max(a,b) ((a)>(b)?a:b)
#define ll long long

int n;
vector<int> seg_tree;
vector<int> arr;

int init_segment_tree(int node, int start, int end)
{
    if(start==end)
    {
        seg_tree[node]=start;
        return 0;
    }

    int mid=(start+end)/2;
    init_segment_tree(node*2, start, mid);
    init_segment_tree(node*2+1, mid+1, end);
    seg_tree[node] = arr[seg_tree[node*2]]<arr[seg_tree[node*2+1]] ? seg_tree[node*2]:seg_tree[node*2+1];
    // 구간에서 높이가 가장 작은 막대의 인덱스를 저장함
    return 0;
}

int shortest(int node, int start, int end, int left, int right)
// 범위에서 가장 작은 막대 인덱스 찾기
{
    if(right < start || left > end)
        return -1;
        // 구간이 범위 밖일때
    if(left <= start && end <= right)
        return seg_tree[node];
        // 구간이 범위 안일때
    
    int mid=(start+end)/2;
    int left_index=shortest(node*2, start, mid, left, right);
    int right_index=shortest(node*2+1, mid+1, end, left, right);

    if(right_index==-1)
        return left_index;
    if(left_index==-1)
        return right_index;

    return arr[left_index]<=arr[right_index] ? left_index:right_index;
}

ll largest(int start, int end)
// 범위에서 가장 큰 사각형 찾기
{
    int shortest_index = shortest(1,0,n-1,start,end);
    ll res=(ll)(end-start+1)*arr[shortest_index];

    if(start<=shortest_index-1)
    // 가장 작은 막대가 시작점이 아니라면
    {
        ll left_res=largest(start, shortest_index-1);
        res=max(res,left_res);
    }

    if(end>=shortest_index+1)
    // 가장 작은 막대가 끝점이 아니라면
    {
        ll right_res=largest(shortest_index+1, end);
        res=max(res,right_res);
    }

    return res;
}

int main(void)
{
    while(1)
    {
        scanf("%d", &n);
        if(n==0)
            return 0;
        
        arr.resize(n);
        seg_tree.resize(4*n);

        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);

        init_segment_tree(1,0,n-1);
        printf("%lld\n", largest(0,n-1));
    }

}