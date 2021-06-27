// https://www.acmicpc.net/problem/11280
// 2021-06-28 02:02:51 44ms
// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kks227&logNo=220803009418
#include<bits/stdc++.h>
using namespace std;

int n,m, scccnt=1; 
vector<vector<int> > graph;
vector<int> finished, visited, sccidx;
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

    if(low_link==visited[now])
    {
        while(true)
        {
            int v=stk.top();
            stk.pop();

            sccidx[v]=scccnt;
            finished[v]++;

            if(v==now)
                break;
        }
        scccnt++;
    }
    return low_link;
}

int main(void)
{
    scanf("%d%d", &n,&m);
    graph.assign(2*n+1, vector<int>());
    finished=visited=sccidx=vector<int>(2*n+1, 0);
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
    {
        if(sccidx[i]==sccidx[2*n-i])
        {
            printf("0");
            return 0;
        }
    }
    printf("1");
}

/* 
-3-> 0
-2-> 1
-1-> 2

1-> 4
2-> 5
3-> 6

-2->0
-1->1

1->3
2->4
*/
