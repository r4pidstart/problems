// https://www.acmicpc.net/problem/17088
// 2022-10-15 05:12:57 28ms
#include"bits/stdc++.h"
using namespace std;

int solution(int idx, int target, vector<int> &arr, int cnt=0)
{
    if(idx == arr.size())
        return cnt;
    
    int ret=INT32_MAX;
    arr[idx]-=1;
    if(!idx or arr[idx] - arr[idx-1] == target)
        ret=min(ret, solution(idx+1, target, arr, cnt+1));
    arr[idx]+=1;
    if(!idx or arr[idx] - arr[idx-1] == target)
        ret=min(ret, solution(idx+1, target, arr, cnt));
    arr[idx]+=1;
    if(!idx or arr[idx] - arr[idx-1] == target)
        ret=min(ret, solution(idx+1, target, arr, cnt+1));
    arr[idx]-=1;

    return ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int difmax=INT32_MIN, difmin=INT32_MAX;
    for(int i=0; i<n-1; i++)
    {
        difmax=max(difmax, arr[i+1]-arr[i]);
        difmin=min(difmin, arr[i+1]-arr[i]);
    }
    if(difmax - difmin > 4)
        return !printf("-1");
    if(n==1)
        return !printf("0");
        
    int ans=INT32_MAX;
    for(int i=difmin; i<=difmax; i++)
        ans=min(ans, solution(0, i, arr));

    // int ans=min({solution(0, arr[1]-arr[0], arr), solution(0, arr[1]-arr[0]+1, arr, 1), solution(0, arr[1]-arr[0]-1, arr, 1)});
    printf("%d", ans!=INT32_MAX ? ans:-1);
}

/*
    
*/