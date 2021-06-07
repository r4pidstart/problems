// https://www.acmicpc.net/problem/2261
// 2021-05-01 02:05:00 60ms
// https://cocoon1787.tistory.com/480

#include<bits/stdc++.h>
using namespace std;

int dist(pair<int,int> a, pair<int,int> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int, int> > points(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &points[i].first, &points[i].second);

    sort(points.begin(), points.end());

    set<pair<int,int> > s;
    int min_dist=INT32_MAX;
    int x_index=0;
    for(int i=0; i<n; i++)
    {
        // 후보의 x좌표와 points[i]의 x좌표 사이의 거리가 현재 최단거리보다 넓을 때 후보에서 삭제
        while(x_index < i)
        {
            int d=(points[i].first-points[x_index].first);
            if(d*d >= min_dist)
            {
                s.erase({points[x_index].second, points[x_index].first});
                x_index++;
            }
            else
                break;
        }

        // set 내부에서 points[i]와 후보의 y좌표중 최단거리 이내에 있는 점에 대해서만 비교
        set<pair<int,int> >::iterator start=s.lower_bound({points[i].second-sqrt(min_dist), -10001});
        set<pair<int,int> >::iterator end=s.upper_bound({points[i].second+sqrt(min_dist), 10001});

        while(start!=end)
        {
            min_dist=min(min_dist, dist({start->second, start->first}, points[i]));
            start++;
        }

        // set에 거꾸로 넣는 이유는 set 내부에서 y 좌표 기반으로 정렬하기 위함.
        s.insert({points[i].second, points[i].first});
    }

    printf("%d", min_dist);
}