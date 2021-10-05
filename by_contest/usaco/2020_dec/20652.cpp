// https://www.acmicpc.net/problem/20652
// 2021-10-06 04:51:58 0ms
#include<bits/stdc++.h>
using namespace std;

struct Point
{
    int x,y,idx,ans=0;
};

bool by_x(Point& a, Point& b)
{
    return a.x<b.x;
}
bool by_y(Point& a, Point& b)
{
    return a.y<b.y;
}
bool by_idx(Point& a, Point& b)
{
    return a.idx<b.idx;
}

vector<Point> north, east;

void get_ans(Point& target, int is_north)
{
    for(auto& check : north)
    {
        if(check.y <= target.y && check.y+check.ans >= target.y)
        {
            if(check.x < target.x) continue;

            int checkLen=target.y-check.y, targetLen=check.x-target.x;
            if(targetLen > checkLen)
                target.ans=min(target.ans, check.x-target.x);
            else if(target.ans==INT32_MAX/2-1 && targetLen < checkLen)
                check.ans=min(check.ans, target.y-check.y);
        }
    }

    // 잘린 경우가 없다면
    if(target.ans==INT32_MAX/2-1)
        target.ans=INT32_MAX/2;
}

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        char d; int a,b; scanf(" \n%c%d%d", &d,&a,&b);
        if(d=='E')
            east.push_back({a,b,i,INT32_MAX/2-1});
        else
            north.push_back({a,b,i,INT32_MAX/2});
    }

    sort(north.begin(), north.end(), by_x);
    sort(east.begin(), east.end(), by_y);

    for(auto& target : east)
        get_ans(target, 0);

    north.insert(north.end(), east.begin(), east.end());
    sort(north.begin(), north.end(), by_idx);

    for(auto& target : north)
        if(target.ans==INT32_MAX/2) printf("Infinity\n");
        else printf("%d\n", target.ans);
}


/*
    
*/