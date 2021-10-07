// https://www.acmicpc.net/problem/20649
// 2021-10-08 04:32:58 0ms
#include<bits/stdc++.h>
using namespace std;

struct Point
{
    int x,y,idx,ans=0,cnt=0;
};

bool by_x(const Point& a, const Point& b) 
{
    return a.x<b.x;
}
bool by_y(const Point& a, const Point& b) 
{
    return a.y<b.y;
}
bool by_idx(const Point& a, const Point& b)
{
    return a.idx<b.idx;
}

vector<Point> north, east;
 
// 경로 구하기
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

// 막힌 지점 찾기
// north -> y++, east -> x++
void get_cnt(Point& target, int is_north)
{
    if(target.ans==INT32_MAX/2) return;

    // 막힌 지점
    int stop=(is_north ? target.y:target.x)+target.ans;
    vector<Point>::iterator next;
    if(is_north) next=lower_bound(east.begin(), east.end(), Point({0,target.y+target.ans,0,0,0}), by_y);
    else next=lower_bound(north.begin(), north.end(), Point({target.x+target.ans,0,0,0,0}), by_x);

    next->cnt++;
    get_cnt(*next, is_north^1);
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

    for(auto& target : east)
        get_cnt(target, 0);
    for(auto& target : north)
        get_cnt(target, 1);

    north.insert(north.end(), east.begin(), east.end());    
    sort(north.begin(), north.end(), by_idx);

    for(auto& target : north)
        printf("%d\n", target.cnt);
}


/*
    
*/