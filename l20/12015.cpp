// https://www.acmicpc.net/problem/12015
// 2021-03-28 22:13:51 224ms
#include<iostream>
#include<vector>
using namespace std;

int binary_search(int target, int start, int end, vector<int> &arr, int *index)
{
    int res=0;
    if(arr[*index-1]<target) // 만약 가장 큰 수 보다 주어진 수가 크다면
    {
        arr[*index]=target;
        *index+=1;
        return 0;
    }

    while(arr[start]<=arr[end]) // 주어진 수보다 작은 수 인덱스 찾기
    {
        int mid=(start+end)/2;

        if(arr[mid]>=target)
        {
            end=mid-1;
            res=mid;
        }
        else // arr[mid]<target
            start=mid+1;
    }
    arr[res]=target;
    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> memo(n,0);
    int index=1;
    int tmp; scanf("%d", &memo[0]);

    for(int i=1; i<n; i++)
    {
        scanf("%d", &tmp);
        binary_search(tmp, 0, index-1, memo, &index);
    }

    printf("%d", index);
}

