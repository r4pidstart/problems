// https://www.acmicpc.net/problem/2672
// 2022-03-06 16:58:45 12ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<vector<pair<int,int> > > table(20001);
    // lo-hi

    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        double x,y,w,h; scanf("%lf%lf%lf%lf", &x, &y, &w, &h);
        x*=10, y*=10, w*=10, h*=10; // 정수화
        for(int i=x; i<x+w; i++)
            table[i].push_back({y, y+h});
    }

    for(int i=0; i<=20000; i++)
        sort(table[i].begin(), table[i].end());

    double ans=0;
    // 중복되는 부분 정리 후 계산
    for(int i=0; i<=20000; i++)
    {
        int start=-1, end=-1;
        for(auto it : table[i])
        {
            if(end < it.first) // 새로운 블럭이면
            {
                ans+=(end-start);
                start=it.first, end=it.second;
            }
            else // 블럭이 겹친다면
            {
                end=max(end, it.second);
            }
        }
        ans+=(end-start);
    }
    int flag=(int)ans%100;
    ans/=100; // x*10 and y*10

    if(flag)
        printf("%.2lf", ans);
    else
        printf("%lld", (long long)ans);
}

/*
    
*/