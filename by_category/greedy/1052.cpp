// https://www.acmicpc.net/problem/1052
// 2022-06-30 21:15:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(100);
    arr[0]=n;

    // 가지고 있는걸로 최대한 줄여보기
    for(int i=0; i<100; i++)
        if(arr[i] > 1)
        {
            arr[i+1]=arr[i]/2;
            arr[i]-=arr[i+1]*2;
            n-=arr[i+1];
        }

    int ans=0, idx=0;
    while(n>k)
    {
        if(idx == 100)
            return !printf("-1");
        if(arr[idx])
        {
            if(arr[idx]==1)
                arr[idx+1]+=1, ans+=pow(2, idx);
            else 
                arr[idx+1]+=1, n-=1;
        }
        idx++;
    }
    printf("%d", ans);
}

/*
    
*/