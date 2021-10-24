// https://www.acmicpc.net/problem/20041
// 2021-10-25 01:30:22 236ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int, int> > police(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &police[i].first, &police[i].second);

    pair<int, int> thief;
    scanf("%d%d", &thief.first, &thief.second);
    
    // up
    int flag1=0;
    for(auto& it : police)
    {
        if(it.second < thief.second) continue;
        int dist=abs(it.first - thief.first); // x죄표 거릐
        if(dist <= it.second-thief.second) flag1++;
    }
    // down
    int flag2=0;
    for(auto& it : police)
    {
        if(it.second > thief.second) continue;
        int dist=abs(it.first - thief.first); // x죄표 거릐
        if(dist <= thief.second-it.second) flag2++;
    }
    // left
    int flag3=0;
    for(auto& it : police)
    {
        if(it.first > thief.first) continue;
        int dist=abs(it.second - thief.second); // y죄표 거릐
        if(dist <= thief.first-it.first) flag3++;
    }
    // right
    int flag4=0;
    for(auto& it : police)
    {
        if(it.first < thief.first) continue;
        int dist=abs(it.second - thief.second); // y죄표 거릐
        if(dist <= it.first-thief.first) flag4++;
    }
    if(!flag1 or !flag2 or !flag3 or !flag4) printf("YES");
    else printf("NO");
}

/*
    
*/