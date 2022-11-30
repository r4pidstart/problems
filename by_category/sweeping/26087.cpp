// https://www.acmicpc.net/problem/26087
// 2022-11-30 23:13:10
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,q; scanf("%d%d", &n, &q);
    vector<pair<int,int> > quary(q);
    for(int i=0; i<q; i++)
        scanf("%d%d", &quary[i].first, &quary[i].second);
    
    vector<int> pibo(n+1), arr(n+1);
    pibo[0]=1, pibo[1]=1;
    for(int i=2; i<=n; i++)
        pibo[i]=(pibo[i-1]+pibo[i-2])%int(1e9+7);
    for(auto it=quary.rbegin(); it!=quary.rend(); it++)
    {
        auto [s,e]=*it;
        int cur=e;

        while(s <= cur)
        {
            if(arr[cur])
                cur=arr[cur]-1; // 이미 뒤에서 갱신된 구간
            else
                arr[cur--]=s;
        }
    }

    for(int i=1; i<=n; i++)
        printf("%d ", arr[i] == 0 ? 0 : pibo[i - arr[i]+1]);
}

/*
    
*/