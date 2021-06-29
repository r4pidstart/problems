// https://www.acmicpc.net/problem/11281
// 2021-06-30 02:03:17 48ms
#include<bits/stdc++.h>
using namespace std;

int scccnt=0;
vector<vector<int> > graph;
vector<int> sccidx, finished, visited;
stack<int> stk;

int targanDFS(int now)
{
    static int visit_cnt=1;
    if(visited[now]) 
        return visited[now];

    int low_link=visited[now]=visit_cnt++;
    stk.push(now);

    for(int next : graph[now])
        if(!finished[next])
            low_link=min(low_link, targanDFS(next));

    if(low_link == visited[now])
    {
        while(true)
        {
            int v=stk.top();
            stk.pop();

            finished[v]++;
            sccidx[v]=scccnt;

            if(now==v)
                break;
        }
        scccnt++;
    }   
    return low_link;
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    graph=vector<vector<int> >(2*n+1, vector<int>());
    sccidx=finished=visited=vector<int>(2*n+1, 0);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[-a+n].push_back(b+n);
        graph[-b+n].push_back(a+n);
    }

    for(int i=0; i<2*n+1; i++)
        if(!finished[i])
            targanDFS(i);

    for(int i=0; i<n; i++)
        if(sccidx[i]==sccidx[2*n-i])
        {
            printf("0");
            return 0;
        }

    printf("1\n");
    for(int i=n+1; i<2*n+1; i++)
        printf("%d ", sccidx[i]<sccidx[2*n-i] ? 1:0);
}

/*
0 -> -3
1 -> -2
2 -> -1
3
4 -> 1
5 -> 2
6 -> 3

-(i-n) + n
-> 2n - i 

만약 x와 neg x의 SCC 번호가 같은 정점이 존재한다면 주어진 논리식을 만족하는 조합은 존재하지 않습니다.
아니라면, x의 SCC 번호가 neg x의 SCC 번호보다 작은 경우 x가 참입니다.
https://blog.qwaz.io/problem-solving/scc%EC%99%80-2-sat
*/
