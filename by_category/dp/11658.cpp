// https://www.acmicpc.net/problem/11658
// 2021-08-10 03:17:18 480ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > num, sum;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    sum.assign(n+1, vector<int>(n+1,0));
    num.assign(n+1, vector<int>(n+1,0));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &num[i][j]);

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            sum[i][j]=sum[i][j-1]+num[i][j];

    for(int j=0; j<m; j++)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd==0)
        {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            num[x][y]=z;

            for(int i=y; i<=n; i++)
                sum[x][i]=sum[x][i-1]+num[x][i];
        }
        else
        {
            int x1,y1,x2,y2; scanf("%d%d%d%d", &x1,&y1,&x2,&y2);

            if(x1>x2) swap(x1,x2);
            if(y1>y2) swap(y1,y2);

            int area_sum=0;
            for(int i=x1; i<=x2; i++)
                area_sum+=sum[i][y2]-sum[i][y1-1];

            printf("%d\n", area_sum);            
        }
    }
}

/*

*/