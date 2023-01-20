// https://www.acmicpc.net/problem/27112
// 2023-01-21 02:05:58
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    sort(arr.begin(), arr.end());

    int day=0, target=0, ans=0;
    while(target < n)
    {
        if(day%7 < 5) arr[target].second--;
        while(target != n and arr[target].second == 0) target++;

        while(target != n and arr[target].first == day+1)
        {
            if(arr[target].second <= day+1 - ans)
            {
                ans+=arr[target].second;
                target++;
            }
            else
                return !printf("-1");
        }
        day++;
    }
    printf("%d", ans);
}

/*
    
*/