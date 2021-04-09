
#include<iostream>
#include<queue>
using namespace std;

const int way[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    int arr[n][m]={};
    getchar(); // remove \n
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            arr[i][j]=getchar();
        getchar(); // remove \n
    }
    
    queue<int> bfs;
    bfs.push(0);
    while(bfs.front()!=(m*n-1))
    // 도착하면 종료
    {
        int x=bfs.front()/m, y=bfs.front()%m;
        bfs.pop();

        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(nx>=0 && nx<n && ny>=0 && ny<m)
            {
                if(arr[nx][ny]=='1')
                {
                    bfs.push(nx*m+ny);
                    arr[nx][ny]=arr[x][y]+1;
                }
            }
        }
    }        
    printf("%d", arr[n-1][m-1]-'0');
}