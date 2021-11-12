// https://www.acmicpc.net/problem/23059
// 2021-11-13 04:00:42 E
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    map<string, vector<string> > m;
    map<string, int> indegree;
    int n; cin>>n;
    for(int i=0; i<n; i++)
    {
        string a,b; cin >> a >> b;
        if(indegree.find(a) == indegree.end()) indegree[a]=0;
        indegree[b]+=1;
        m[a].push_back(b); // b를 구매하기 위해 필요한 건 a
    }
    // 위상정렬
    // 구매할 수 있는 아이템은 사전순으로 구매.
    vector<string> buyList, tmp;
    queue<pair<string, int> > q;
    for(auto it : indegree)
        if(it.second==0) q.push({it.first,0});

    int prev=0;
    while(!q.empty())
    {
        auto now=q.front(); q.pop();
        if(prev != now.second)
        {
            sort(tmp.begin(), tmp.end());
            buyList.insert(buyList.end(), tmp.begin(), tmp.end());
            prev=now.second;
            tmp.assign(0,"");
        }

        // 다음거 큐에 넣기
        if(m.find(now.first) != m.end())
        {
            for(string& next : m[now.first])
                if(!--indegree[next])
                    q.push({next, now.second+1});
        }
        tmp.push_back(now.first);
    }

    sort(tmp.begin(), tmp.end());
    buyList.insert(buyList.end(), tmp.begin(), tmp.end());

    // 다 못 사는 경우는?
    if(indegree.size() != buyList.size()) cout<<-1;
    else for(auto s : buyList) cout<<s<<'\n';
}

/*
    
*/