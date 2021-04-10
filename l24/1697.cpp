// https://www.acmicpc.net/problem/1697
// 2021-04-10 21:49:36 0ms
#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
    int arr[100001]={};
    int n,k; scanf("%d%d", &n, &k);
    queue<int> bfs;
    bfs.push(n);
    arr[n]=1;
    while(bfs.front()!=k)
    {
        int now=bfs.front();
        bfs.pop();
        if(now+1<100001)
                if(arr[now+1]==0)
                {
                    arr[now+1]=arr[now]+1;
                    bfs.push(now+1);
                }
        if(now-1>=0)
                if(arr[now-1]==0)
                {
                    arr[now-1]=arr[now]+1;
                    bfs.push(now-1);
                }
        if(now*2<100001)
                if(arr[now*2]==0)
                {
                    arr[now*2]=arr[now]+1;
                    bfs.push(now*2);
                }
    }
    printf("%d", arr[bfs.front()]-1);
    return 0;
}