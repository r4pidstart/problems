// https://www.acmicpc.net/problem/23632
// 2021-11-25 21:38:09 964ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,t; scanf("%d%d%d", &n,&m,&t);
    vector<int> alreadyBuilt(n+1);
    
    vector<vector<int> > requiredResource(n+1, vector<int>()), // 건물을 짓는데 필요한 자원
                         resource(n+1, vector<int>()), // 자원으로 지을 수 있는 건물
                         producedResource(n+1, vector<int>()); // 건물이 생산하는 자원
    
    for(int i=0; i<m; i++)
    {
        int tmp; scanf("%d", &tmp);
        alreadyBuilt[tmp]=1;
    }

    for(int i=0; i<n; i++)
    {
        int c; scanf("%d", &c);
        while(c--)
        {
            int tmp; scanf("%d", &tmp);
            producedResource[i+1].push_back(tmp);
        }
    }

    for(int i=0; i<n-m; i++)
    {
        int now,cnt; scanf("%d%d", &now, &cnt);
        while(cnt--)
        {
            int tmp; scanf("%d", &tmp);
            requiredResource[now].push_back(tmp);
            resource[tmp].push_back(now);
        }
    }

    // 지어진 건물 처리
    queue<pair<int, int> > q;
    vector<int> availableResource(n+1,0), builtBuilding(n+1,0);
    for(int i=0; i<=n; i++)
        if(alreadyBuilt[i]) q.push({i,0});

    while(!q.empty())
    {
        int now=q.front().first, nowTime=q.front().second; q.pop();
        // 이미 지어졌는지 체크.
        if(nowTime > t) continue;
        if(builtBuilding[now]) continue;
        builtBuilding[now]=1;

        for(auto& i : producedResource[now]) 
            availableResource[i]=1;
        // 해당 건물을 통해 만들 수 있는 자원이 필요한 건물들을 확인
        int builded=0;
        for(auto& i : producedResource[now])
        {
            for(auto& j : resource[i])
            {
                if(builtBuilding[j]) continue;

                int flag=0;
                for(auto& k : requiredResource[j])
                    if(!availableResource[k]) flag++;

                if(!flag) q.push({j, nowTime+1}), builded++;
            }
        }
    }

    printf("%d\n", accumulate(builtBuilding.begin(), builtBuilding.end(), 0));
    for(int i=1; i<=n; i++)
        if(builtBuilding[i]) printf("%d ", i);
}

/*
    
*/