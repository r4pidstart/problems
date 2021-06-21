// 12-2 ARCTIC
// https://algospot.com/judge/problem/read/ARCTIC

#include<bits/stdc++.h>
using namespace std;

struct Coordinate
{
    double x,y;
};

vector<vector<pair<double,int> > > dist;
vector<Coordinate> xy;
int n; 

double get_dist(Coordinate a, Coordinate b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
}

int decision(double output)
{
    vector<int> visited(n, 0);
    int reached=0;
    stack<int> stk;
    stk.push(0);

    while(!stk.empty())
    {
        int now=stk.top();
        stk.pop();
        if(visited[now])
            continue;

        visited[now]++;
        reached++;
        for(auto& next : dist[now])
        {
            if(next.first > output)
                break;
            stk.push(next.second);
        }
    }
    return reached==n ? 1:0; // 가능하면 1을 반환
}

double optimize()
{
    double lo=0, hi=1000*1000;
    for(int it=0; it<100; it++)
    {
        double mid=(lo+hi)/2;
        (decision(mid) ? hi:lo)=mid;
    }
    return lo;
}

int main(void)
{
    int c; scanf("%d", &c);
    while(c--)
    {
        scanf("%d", &n);
        xy.assign(n,Coordinate());
        dist.assign(n, vector<pair<double,int> >());
        for(int i=0; i<n; i++)
        {
            double a,b; scanf("%lf%lf", &a,&b);
            xy[i]={a,b};
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dist[i].push_back({get_dist(xy[i], xy[j]), j});
        
        for(int i=0; i<n; i++)
            sort(dist[i].begin(), dist[i].end()); 

        printf("%.2lf\n", optimize());
    }
} 

/*
1. 각 기지간의 거리를 구하기
2. 이분법을 이용해 결정문제 형태로 바꾸기
    -> x보다 작은 무전기의 출력으로 모든 기지가 연락할 수 있을까?
*/