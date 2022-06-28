// https://www.acmicpc.net/problem/17226
// 2022-06-28 10:04:18 20ms
#include"bits/stdc++.h"
using namespace std;

int test=0;
struct str
{
    int first,second,idx;
    bool operator<(const str& a) const
    {
        return second < a.second;
    } 
};

int dfs(vector<int>& used, vector<str>& mine, vector<str>&yours, deque<pair<int,int> >& q, int n)
{
    if(n == mine.size())
    {
        // modok check
        int cnt=0;
        for(auto it : yours)
            if(it.second) cnt++;
        
        if(!cnt) 
            return 1;

        vector<int> check(13);
        check[0]=1;
        for(auto it : mine)
            check[it.second]++;
        for(auto it : yours)
            check[it.second]++;
        
        for(int i=1; i<13; i++)
            if(!check[i-1] and check[i]) 
                return 0;
        
        return test=1;
    }

    // use cards
    int i = n;
    for(int j=0; j<yours.size()+1; j++)
    {
        if(j==yours.size()) // 공격 안 할 수도 있음
        {
            used[i]=-1;
            if(dfs(used, mine, yours, q, n+1))
                return 1;
            used[i]=0;
            continue;
        }

        if(yours[j].second==0) continue; // 이미 죽음. 못 떄림.

        used[i]=j+1;
        int tmp1=mine[i].second, tmp2=yours[j].second;
        mine[i].second=max(0, mine[i].second-yours[j].first);
        yours[j].second=max(0, yours[j].second-mine[i].first);
        q.push_back({mine[i].idx, j});
        if(dfs(used, mine, yours, q, n+1))
            return 1;
        q.pop_back();
        mine[i].second=tmp1;
        yours[j].second=tmp2;
        used[i]=0;
    }

    return 0;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    // 공격력, 생명력
    vector<str> mine(n), yours(m);
    for(int i=0; i<n; i++)
        scanf("%d %d", &mine[i].first, &mine[i].second), mine[i].idx=i;
    for(int i=0; i<m; i++)
        scanf("%d %d", &yours[i].first, &yours[i].second);

    sort(mine.begin(), mine.end());
    
    if(m==0) // 예외
        return !printf("0");

    vector<int> used(n);
    deque<pair<int, int> > q;
    if(dfs(used, mine, yours, q, 0))
    {
        printf("%lu\n", q.size()+test);
        for(auto it : q)
            printf("attack %d %d\n", it.first+1, it.second+1);
        if(test) printf("use modok");
    }
    else
        printf("-1");
}

/*
    
*/