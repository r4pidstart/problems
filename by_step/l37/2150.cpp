// https://www.acmicpc.net/problem/2150
// 2021-06-10 11:42:00 32ms
// https://blog.naver.com/uss425/222193890263
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > dest, scc_arr;
vector<int> visited, checked;
stack<int> stk;

int get_scc(int now)
{
    if(visited[now]!=0)
        return visited[now];

    static int visit_cnt=1;
    stk.push(now);

    int low_link=visited[now]=visit_cnt++;
    for(int next : dest[now])
        if(checked[next]==0)
            low_link=min(low_link, get_scc(next));

    if(low_link == visited[now]) // 사이클이 있으면
    {
        vector<int> scc;
        while(1) // 연결된 정점 확인
        {
            int t=stk.top();
            scc.push_back(t);
            stk.pop();
            checked[t]++;

            if(t==now)
                break;
        }
        sort(scc.begin(), scc.end());
        scc_arr.push_back(scc);
    }
    return low_link;
}

int main(void)
{
    int v,e; scanf("%d%d", &v, &e);
    dest.assign(v+1, vector<int>());
    visited.assign(v+1,0), checked.assign(v+1, 0);
    for(int i=0; i<e; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        dest[a].push_back(b);
    }

    for(int i=1; i<v+1; i++)
        if(visited[i]==0)
            get_scc(i);

    sort(scc_arr.begin(), scc_arr.end());

    int s=scc_arr.size();
    printf("%d\n", s);
    for(int i=0; i<s; i++)
    {
        for(auto v : scc_arr[i])
            printf("%d ", v);
        printf("-1\n");
    }
}