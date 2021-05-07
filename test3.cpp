
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
    int modtwo=two%1001;
    int next=max(one,modtwo)+1;
    int test1=dp[one][next]+get_dist(two,next);
    int test2=dp[next][two]+get_dist(one,next);
    int target=dp[one][modtwo];
    if(dp[one][modtwo] == dp[one][next]+get_dist(two, next))
    {
        printf("2");
        get_route(one, next);
    }
    else
    {
        printf("1");
        get_route(next, two);
    }
}

int main(void)
{
    scanf("%d%d", &n,&w);
    event[0]={1,1}, event[1001]={n,n};
    for(int i=0; i<w; i++)
        scanf("%d%d", &event[i+1].first, &event[i+1].second);
    printf("%d\n", solution(0,1001));
    get_route(0,1001);
}