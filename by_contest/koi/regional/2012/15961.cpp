// https://www.acmicpc.net/problem/15961
// 2022-04-30 09:49:04 516ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,d,k,c; scanf("%d%d%d%d", &n, &d, &k, &c);
    vector<int> arr(n+1), sushi(d+1);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);
    for(int i=1; i<=n; i++)
        arr.push_back(arr[i]);
    
    int sushi_cnt=0;
    for(int i=1; i<k; i++)
    {
        if(!sushi[arr[i]]) sushi_cnt++;
        sushi[arr[i]]++;
    }
    
    int ans=0;
    for(int i=k; i<=n+k; i++)
    {
        // 마지막 초밥 추가, 첫 번째 초밥 제거
        if(--sushi[arr[i-k]] == 0)
            sushi_cnt--;
        if(sushi[arr[i]]++ == 0)
            sushi_cnt++;
        ans=max(ans, sushi_cnt + (!sushi[c]));
    }
    printf("%d", ans);    
}

/*
    1 2 3 4 1 2 3 4
*/