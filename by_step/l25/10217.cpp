// https://www.acmicpc.net/problem/10217
// 2021-04-24 17:48:33 2820ms
#include<bits/stdc++.h>
using namespace std;

typedef struct {int dest, cost, time;}_ticket;
typedef struct {int now, t_cost, t_time;}_pq;

struct compare {
	bool operator()(const _pq &f, const _pq &s) {
		return f.t_time > s.t_time;
	}
};

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m,k,u,c,v,d;
        scanf("%d%d%d", &n,&m,&k);
        vector<_ticket> ticket[101]; 
        vector<vector<int> > dp_time(101, vector<int>(10001, INT32_MAX));
        // time[1][0] -> 1까지 0원으로 갈 수 있는 거리

        for(int i=0; i<k; i++)
        {
            scanf("%d%d%d%d", &u,&c,&v,&d);
            ticket[u].push_back({c,v,d});
        }

        priority_queue<_pq, vector<_pq>, compare> pq;
        dp_time[1][0]=0;
        pq.push({1,0,0});
        while(!pq.empty())
        {
            int now=pq.top().now, cost=pq.top().t_cost, time=pq.top().t_time;
            pq.pop();

            if(time>dp_time[now][cost])
                continue;

            for(auto next : ticket[now])
            {
                if(dp_time[next.dest][cost+next.cost]>time+next.time && cost+next.cost<=m)
                {
                    dp_time[next.dest][cost+next.cost]=time+next.time;
                    pq.push({next.dest, cost+next.cost, time+next.time});
                }
            }
        }
        int answer=INT32_MAX;
        for(int i=0; i<=m; i++)
            answer=min(answer,dp_time[n][i]);

        if(answer==INT32_MAX)
            printf("Poor KCM\n");
        else
            printf("%d\n", answer);
    }
}

