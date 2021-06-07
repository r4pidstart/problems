// https://www.acmicpc.net/problem/2263
// 2021-05-05 02:02:24 48ms
#include<bits/stdc++.h>
using namespace std;

vector<int> in, post, in_pos(100000,-1);

void solution(int in_1, int in_2, int post_1, int post_2)
{
    if(in_1>in_2 || post_1>post_2)
        return;
    int root=post[post_2];
    printf("%d ", root);
    solution(in_1, in_pos[root]-1, post_1, post_1+in_pos[root]-in_1-1);
    solution(in_pos[root]+1, in_2, post_1+in_pos[root]-in_1, post_2-1);
}

int main(void)
{
    int n; scanf("%d", &n);
    in.resize(n), post.resize(n);
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        in[i]=tmp, in_pos[tmp]=i;
    }
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        post[i]=tmp;
    }
    solution(0, n-1, 0, n-1);
}