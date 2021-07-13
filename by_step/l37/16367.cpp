// https://www.acmicpc.net/problem/16367
// 2021-07-13 22:32:53 8ms
#include<bits/stdc++.h>
using namespace std;

int scccnt=1;
stack<int> stk;
vector<vector<int> > graph;
vector<int> sccidx, finished, visited;

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

            if(v==now)
                break;
        }
        scccnt++;
    }
    return low_link;
}

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    sccidx=finished=visited=vector<int>(2*n+1, 0);
    graph=vector<vector<int> >(2*n+1, vector<int>());

    for(int i=0; i<k; i++)
    {
        int n1, n2, n3; char c1, c2, c3;
        scanf("%d %c %d %c %d %c", &n1, &c1, &n2, &c2, &n3, &c3);
        n1=c1=='B' ? -n1:n1, n2=c2=='B' ? -n2:n2, n3=c3=='B' ? -n3:n3;            
        // if A->B, A -> ~B , ~A->B
        graph[-n1+n].push_back(n2+n);
        graph[-n2+n].push_back(n1+n);
        graph[-n2+n].push_back(n3+n);
        graph[-n3+n].push_back(n2+n);
        graph[-n1+n].push_back(n3+n);
        graph[-n3+n].push_back(n1+n);
    }

    for(int i=0; i<2*n+1; i++)
        if(!finished[i])
            targanDFS(i);

    for(int i=0; i<n; i++)
        if(sccidx[i]==sccidx[2*n-i])
        {
            printf("-1");
            return 0;
        }
    
    for(int i=n+1; i<2*n+1; i++)
    {
        printf("%c", sccidx[i]<sccidx[2*n-i] ? 'R':'B');
    }
}

/*
    B -> -, R -> +
    A or B or C 중 2개 이상 선택
    -> (A or B) and (B or C) and (C or A)로 바꿀 수 있음

    -3
    -2
    -1 -> 2
    0
    1 -> 4
    2
    3
*/
