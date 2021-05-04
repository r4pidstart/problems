// https://www.acmicpc.net/problem/1991
// 2021-05-04 16:43:25 0ms
#include<bits/stdc++.h>
using namespace std;

vector<char> pre,in,post;
map<char, pair<char,char> > tree;

void traversal(char now)
{
    pre.push_back(now);
    if(tree.find(now)!=tree.end() && tree[now].first!='.')
        traversal(tree[now].first);
    in.push_back(now);
    if(tree.find(now)!=tree.end() && tree[now].second!='.')
        traversal(tree[now].second);
    post.push_back(now);
}

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        char a,b,c; scanf("\n%c %c %c", &a, &b, &c);
        tree[a]={b,c};
    }
    traversal('A');
    for(char target : pre)
        printf("%c", target);
    printf("\n");
    for(char target : in)
        printf("%c", target);
    printf("\n");
    for(char target : post)
        printf("%c", target);
}