// http://220.89.64.243/30stair/depth/depth.php?pname=depth
//
#include<bits/stdc++.h>
using namespace std;

int max_depth=0, cnt=0;

void dfs(int dep)
{
    max_depth=max(max_depth, dep);

    int deg=0, left, right;
    // left
    scanf("%d", &left);
    if(left!=-1)
    {
        dfs(dep+1);
        deg++;
    }
    // right
    scanf("%d", &right);
    if(right!=-1)
    {
        dfs(dep+1);
        deg++;
    }

    if(deg==2) cnt++;
}

int main(void)
{
    getchar();
    dfs(1);
    printf("%d\n%d", cnt, max_depth);
}

/*
    
*/