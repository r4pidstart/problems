
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

vector<int> dest[20001];
int arr[20001];
queue<int> bfs_q;

int reset(int v)
{
    memset(arr+1,0,sizeof(int)*v);
    bfs_q=queue<int>();
    for(int i=1; i<=v; i++)
        dest[i].clear();
    return 0;
}

int bfs(int target)
{
    bfs_q.push(target);
    arr[target]=1;
    while(!bfs_q.empty())
    {
        int now=bfs_q.front();
        bfs_q.pop();

        for(int next : dest[now])
        {
            if(arr[next]==0)
            {
                if(arr[now]==1)
                    arr[next]=2;
                else
                    arr[next]=1;
                bfs_q.push(next);
            }
            else // if(arr[next]!=0)
            {
                if(arr[now]==arr[next])
                    return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int v,e; scanf("%d%d", &v,&e);
        reset(v);
        int one,two,flag=0;
        for(int i=0; i<e; i++)
        {
            scanf("%d%d", &one,&two);
            dest[one].push_back(two);
            dest[two].push_back(one);
        }
        for(int i=1; i<=v; i++)
        {
            if(arr[i]==0) // 방문하지 않았으면
                if(bfs(i)==1)
                {
                    printf("NO\n");
                    flag=1;
                    break;
                }
        }
        if(flag==0)
            printf("YES\n");
    }
    return 0;
}