// https://www.acmicpc.net/problem/28070
// 2023-07-04 21:57:11
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<pair<int, int> > arr(n);
    for(int i=0; i<n; i++)
    {
        int sy,sm,ey,em; scanf("%d-%d %d-%d", &sy, &sm, &ey, &em);
        arr[i]={sy*13+sm, ey*13+em};
    }

    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<> > pq;
    int ans=-1, m_cnt=0;
    for(int i=0; i<n; i++)
    {
        while(pq.size() and arr[i].first>pq.top()) pq.pop();
        pq.push(arr[i].second);
        if(pq.size() > m_cnt)
            ans=arr[i].first, m_cnt=pq.size();
    }
    printf("%4d-%02d\n", ans/13, ans%13);
}

/*
    
*/