// https://www.acmicpc.net/problem/17951
// 2021-10-30 23:02:00 12ms
#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
int decision(int mid, int k)
{
    // 최소 부분합이 mid 이상이 되도록 k개 이상 분할 할 수 있는지 확인
    int tmp=0, cnt=0;
    for(int i=0; i<arr.size(); i++)
    {
        tmp+=arr[i];
        if(tmp>=mid) tmp=0, cnt++;
    }
    return cnt>=k ? 1:0;
}

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    arr.assign(n,0);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    // k개로 나눴을 때의 최소 점수를 이용한 파라메트릭 서치
    int lo=0, hi=n*20, ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid, k))
        {
            ans=mid;
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
    printf("%d", ans);
}

/*
    
*/