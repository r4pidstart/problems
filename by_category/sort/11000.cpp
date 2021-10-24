// https://www.acmicpc.net/problem/11000
// 2021-10-25 02:30:22 58ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<int> > lecture_room;
    lecture_room.push(0);
    for(auto& it : arr)
    {
        if(lecture_room.top() <= it.first)
            lecture_room.pop();
        lecture_room.push(it.second);
    }
    printf("%d", (int)lecture_room.size());
}

/*
    
*/