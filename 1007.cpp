// https://www.acmicpc.net/problem/1007
// 2021-07-01 01:13:14 248ms
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > points;

double get_length(bitset<20> mask, int n)
{
    long long x=0, y=0;
    for(int i=0; i<n; i++)[]
    {
        if(mask[i])
            x+=points[i].first, y+=points[i].second;
        else
            x-=points[i].first, y-=points[i].second;
    }
    return sqrt(x*x+y*y);
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        points.assign(n, pair<int,int>());
        for(int i=0; i<n; i++)
            scanf("%d%d", &points[i].first, &points[i].second);

        double ans=DBL_MAX;
        for(int i=0; i<(1<<n); i++)
        {
            bitset<20> mask=i;
            if(mask.count()==n/2) // 절반을 선택하기
                ans=min(ans, get_length(mask, n));
        }
        printf("%lf\n", ans);
    }
}

/*

*/