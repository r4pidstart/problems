// https://www.acmicpc.net/problem/1379
// 2023-02-12 00:08:02
#include"bits/stdc++.h"
#include <queue>
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    // begin, end, num
    vector<pair<pair<int, int>, int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d %d %d", &arr[i].second, &arr[i].first.first, &arr[i].first.second);
    sort(arr.begin(), arr.end());

    // end time, room number
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
    vector<int> ans(n);
    int room_cnt=0;
    list<int> room;
    for(auto it : arr)
    {
        while(pq.size() and pq.top().first <= it.first.first)
            room.push_back(pq.top().second), pq.pop();
        if(!room.size()) room.push_back(++room_cnt);

        pq.push({it.first.second, room.front()});
        ans[it.second-1]=room.front();
        room.pop_front();
    }
    printf("%d\n", room_cnt);
    for(auto it : ans)
        printf("%d\n", it);
}

/*
    
*/