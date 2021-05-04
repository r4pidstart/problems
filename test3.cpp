#include<bits/stdc++.h>
using namespace std;
#define it vector<int>::iterator
vector<int> ans, in, post;

int solution(it in_1, it in_2, it post_1, it post_2)
{
    if(in_2-in_1==1)
    {
        ans.push_back(*in_1);
        return 0;
    }
    if(in_2-in_1==2)
    {
        ans.push_back(*(in_1+1));
        ans.push_back(*in_1);
        return 0;
    }
    int root=find(in_1, in_2, *(post_2-1))-in_1;
    ans.push_back(in_1[root]);
    solution(in_1, in_1+root, post_1, post_1+root);
    solution(in_1+root+1, in_2, post_1+root, post_2-1);
}

int main(void)
{
    int n; scanf("%d", &n);
    in.resize(n), post.resize(n);
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        in[i]=tmp;
    }
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        post[i]=tmp;
    }
    solution(in.begin(), in.end(), post.begin(), post.end());
    for(int target : ans)
        printf("%d ", target);
}