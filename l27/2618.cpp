// https://www.acmicpc.net/problem/2618
// 2021-05-07 19:58:21 20ms
#include<bits/stdc++.h>
using namespace std;

int n,w;
vector<vector<int> > dp(1001, vector<int>(1001, -1));
pair<int,int> event[1002]; 

int get_dist(int a, int b)
{
    return abs(event[a].first-event[b].first) + abs(event[a].second-event[b].second);
}

int solution(int one, int two)
{
    if(one == w || two == w) return 0;
    int modtwo=two%1001;
    if(dp[one][modtwo]==-1)
    {
        int next=max(one,modtwo)+1;
        int d1=solution(next, two)+get_dist(one,next),
            d2=solution(one, next)+get_dist(next,two);
        dp[one][two]=min(d1,d2);
    }
    return dp[one][two];
}

void get_route(int one, int two)
{
    if(one == w || two == w) return;
    int next=max(one,two%1001)+1;
    int d1=dp[next][two]+get_dist(one, next),
        d2=dp[one][next]+get_dist(two, next);
    if(d1<d2)
    {
        printf("1\n");
        get_route(next, two);
    }
    else
    {
        printf("2\n");
        get_route(one, next);
    }
}

int main(void)
{
    scanf("%d%d", &n,&w);
    event[0]={1,1}, event[1001]={n,n};
    for(int i=0; i<w; i++)
        scanf("%d%d", &event[i+1].first, &event[i+1].second);
    dp[0][0]=solution(0,1001);
    printf("%d\n", dp[0][0]);
    get_route(0,1001);
}