// https://www.acmicpc.net/problem/2261
// 2021-04-30 23:51:15 TLE

#include<bits/stdc++.h>
using namespace std;

int dist(pair<int,int> a, pair<int,int> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > points(20001);
    for(int i=0; i<n; i++)
    {
        int x,y; scanf("%d%d", &x, &y);
        points[x+10000].push_back(y);
    }

    // 직선 하나를 이동시킴
    // 만나는 점을 리스트에 넣고, 리스트에 있는 점들과 거리를 비교함
    // 리스트에 있는 점과, 직선과의 최단거리가 최소거리보다 클 때에는 리스트에서 제거함
    deque<pair<int,int> > list;
    int min_dist=INT32_MAX;
    for(int x_pos=0; x_pos<20001; x_pos++)
    {
        if(points[x_pos].size()==0)
            continue;

        while(x_pos - list.front().first >= min_dist)
        {
            int pop_size=points[list.front().first].size();
            while(pop_size--)
                list.pop_front();
        }

        for(auto y_it=points[x_pos].begin(); y_it!=points[x_pos].end(); y_it++)
        {
            for(auto it=list.begin(); it!=list.end(); it++)
                min_dist=min(min_dist, dist(*it, make_pair(x_pos, *y_it)));
            list.push_back(make_pair(x_pos, *y_it));
        }
    }

    printf("%d", min_dist);
}