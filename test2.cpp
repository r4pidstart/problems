
#include<bits/stdc++.h>
using namespace std;
#define it vector<int>::iterator

// 후위 배열 맨 뒤 번호를 중위 배열에서 찾기
// 찾은 번호를 일단 ans에 푸시.
// 찾은 번호를 기준으로 앞 뒤로 나눠 다시 시행
// 앞 뒤로 나눌 때, 원소가 하나라면 출력, 두개라면 역순으로 출력
vector<int> in, post, in_pos(100000,-1);

void solution(int in_1, int in_2, int post_1, int post_2)
{
    if(in_2-in_1==1)
    {
        printf("%d ", in[in_1]);
        return;
    }
    if(in_2-in_1==2)
    {
        printf("%d %d ", in[in_1+1], in[in_1]);
        return;
    }
    int root=in_pos[post[post_2-1]];
    printf("%d ", in[root]);
    solution(in_1, root, post_1, post_1+root-in_1-1);
    solution(root+1, in_2, post_1+root-in_1, post_2-1);
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
    solution(0, n, 0, n);
}