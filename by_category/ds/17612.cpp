// https://www.acmicpc.net/problem/17612
// 2022-01-07 03:38:50 52ms
#include<bits/stdc++.h>
using namespace std;

struct inSt
{
    int endTime, casherNum;
    bool operator<(const inSt& a) const
    {
        if(endTime == a.endTime) return casherNum>a.casherNum;
        else return endTime>=a.endTime;
    }
};

struct outSt
{
    int endTime, casherNum, customerId;
    bool operator<(const outSt& a) const
    {
        if(endTime == a.endTime) return casherNum<a.casherNum;
        else return endTime>=a.endTime; 
    }
};

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    priority_queue<inSt> pqIn; // 가장 빠르게 끝나는, 번호가 작은 계산대
    priority_queue<outSt> pqOut; // 가장 빠르게 끝날, 번호가 큰 계산대

    for(int i=0; i<k; i++)
        pqIn.push({0,i});

    vector<pair<int, int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    long long ans=0, outCnt=0;

    for(int i=0; i<n; i++)
    {
        if(pqIn.empty() or (!pqOut.empty() and pqIn.top().endTime >= pqOut.top().endTime) )
        {
            // 같은 시간에 끝나는게 여러개 있으면 순서를 고려해서 빼야 함
            int targetTime=pqOut.top().endTime;
            while(!pqOut.empty() and pqOut.top().endTime == targetTime)
            {
                pqIn.push({pqOut.top().endTime, pqOut.top().casherNum});
                ans+=++outCnt*pqOut.top().customerId;
                pqOut.pop();
            }
        }

        pqOut.push({pqIn.top().endTime+arr[i].second, pqIn.top().casherNum, arr[i].first});
        pqIn.pop();
    }

    while(!pqOut.empty())
    {
        pqIn.push({pqOut.top().endTime, pqOut.top().casherNum});
        ans+=++outCnt*pqOut.top().customerId;
        pqOut.pop();
    }

    printf("%lld",ans);
}

/*
    
*/