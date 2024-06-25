// https://www.acmicpc.net/problem/13160
// 2024-06-26 09:28:06
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<tuple<int, int, int> > arr(n);
    for(int i=0; i<n; i++)
    {
        int a,b; cin >> a >> b;
        arr[i]={a, b, i+1};
    }

    sort(arr.begin(), arr.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    
    int max_cnt=0;
    for(int i=0; i<n; i++)
    {
        while(pq.size() and pq.top().first < get<0>(arr[i]))
            pq.pop();
        pq.push({get<1>(arr[i]), get<2>(arr[i])});

        max_cnt=max(max_cnt, (int)pq.size());
    }
    
    while(pq.size())
        pq.pop();

    for(int i=0; i<n; i++)
    {
        while(pq.size() and pq.top().first < get<0>(arr[i]))
            pq.pop();
        pq.push({get<1>(arr[i]), get<2>(arr[i])});

        if(pq.size() == max_cnt)
            break;
    }
    
    cout << max_cnt << '\n';
    while(pq.size())
    {
        auto [a, b]=pq.top();
        pq.pop();
        cout << b << ' ';
    }
}

/*
    
*/