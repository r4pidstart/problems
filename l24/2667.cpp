// https://www.acmicpc.net/problem/2667
// 2021-04-08 02:07:59 0ms
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int way[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int main(void)
{
    int n; scanf("%d", &n);
    char arr[n][n], visited[n][n]={};
    getchar(); // remove \n
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            scanf("%c", &arr[i][j]);
        getchar();
    }
    
    queue<int> bfs;
    vector<int> count;
    for(int i=0; i<n*n; i++)
    {
        if(arr[i/n][i%n]=='1' && visited[i/n][i%n]==0)
        {
            bfs.push(i);
            count.push_back(1);
            visited[i/n][i%n]=1;
            while(!bfs.empty())
            {
                int x=bfs.front()/n, y=bfs.front()%n;
                bfs.pop();
                
                for(int w=0; w<4; w++)
                {
                    int nx=x+way[w][0], ny=y+way[w][1];
                    if(nx>=0 && nx<n && ny>=0 && ny<n)
                    {
                        if(arr[nx][ny]=='1' && visited[nx][ny]==0)
                        {
                            bfs.push(nx*n+ny);
                            visited[nx][ny]=1;
                            count[count.size()-1]++;
                        }
                    }
                }               
            }
        }
    }
    printf("%d\n", (int)count.size());
    sort(count.begin(), count.end());
    for(int res : count)
        printf("%d\n", res);
}