#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdint.h>

#define next_idx(now) (now=(now+1)%(n*2))

typedef struct node
{
    int to, dist;
    struct node *next;
}node;

int push_back(node **n, int to, int dist)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->to=to, tmp->dist=dist;
    tmp->next=*n;
    *n=tmp;
    return 0;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    node* graph[n+1];
    for(int i=0; i<n+1; i++)
        graph[i]=0;

    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        push_back(&graph[a], b, c);
        push_back(&graph[b], a, c);
    }

    int ans[n+1][n+1];

    int q[2*n];
    for(int i=1; i<=n; i++)
    {
        int front=0, rear=0;
        int inq[2*n], prev[2*n], dist[2*n];
        for(int i=0; i<2*n; i++)
            inq[i]=0, prev[i]=-1, dist[i]=INT32_MAX/2;
        
        dist[i]=0, q[next_idx(rear)]=i, inq[i]=1, prev[i]=i;
        while(front!=rear)
        {
            int now=q[next_idx(front)];
            inq[now]=0;

            node *cur=graph[now];
            while(cur)
            {   
                int next=cur->to, ndist=cur->dist;
                if(dist[next] > dist[now]+ndist)
                {
                    dist[next]=dist[now]+ndist;
                    prev[next]=now;
                    if(!inq[next])
                        inq[next]=1, q[next_idx(rear)]=next;
                }
                cur=cur->next;
            }
        }

        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;
            int cur=j;
            while(cur != i)
            {
                if(prev[cur] == i) ans[i][j]=cur;
                cur=prev[cur];
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            if(i==j) printf("- ");
            else printf("%d ", ans[i][j]);
        printf("\n");
    }
}

/*

*/
