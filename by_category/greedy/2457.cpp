// https://www.acmicpc.net/problem/2457
// 2021-12-05 00:10:13 44ms
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > date;

int idx=0;
int check(int tmpend)
{
    int ret=0;
    while(idx < date.size() and date[idx].first <= tmpend)
    {
        ret=max(ret, date[idx].second);
        idx++;
    }
    return ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    // 월/일 을 일로 바꾸기
    vector<int> month{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> psum(13, 0);
    for(int i=0; i<12; i++) psum[i+1]=psum[i]+month[i];
    for(int i=0; i<n; i++)
    {
        int a,b,c,d; scanf("%d%d%d%d", &a,&b,&c,&d);
        date.push_back({psum[a-1]+b, psum[c-1]+d});
    }
    sort(date.begin(), date.end());

    int tmpend=psum[2]+1, end=psum[11], ans=0;
    while(tmpend <= end)
    {
        tmpend=check(tmpend);
        ans++;
        if(tmpend==0) break;
    }
    printf("%d", tmpend ? ans:0);
}

/*
    
*/