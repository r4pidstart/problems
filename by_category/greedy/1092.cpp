// https://www.acmicpc.net/problem/1092
// 2021-11-21 22:57:00 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> crane, item, craneIdx, selItem;
    int n,m; scanf("%d", &n);
    crane.assign(n,0);
    for(int i=0; i<n; i++) scanf("%d", &crane[i]);

    scanf("%d", &m);
    item.assign(m,0);
    for(int i=0; i<m; i++) scanf("%d", &item[i]);

    sort(crane.begin(), crane.end(), greater<int>());
    sort(item.begin(), item.end(), greater<int>());
    assert(n>0 and m>0);
    if(crane[0] < item[0]) return !printf("-1");

    craneIdx.assign(n,0);
    selItem.assign(m,0);

    int ans=0, cnt=0;
    while(cnt != item.size())
    {
        // 모든 크레인에 대해 실을 수 있는 가장 무거운 상품을 실음
        for(int i=0; i<crane.size(); i++)
        {
            while(craneIdx[i]<item.size() and (selItem[craneIdx[i]] or item[craneIdx[i]]>crane[i])) craneIdx[i]++;
            if(craneIdx[i]<item.size() and !selItem[craneIdx[i]]) selItem[craneIdx[i]]++, cnt++;
        }
        ans++;
    }

    printf("%d", ans);
}

/*
    
*/