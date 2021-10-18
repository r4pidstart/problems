// http://220.89.64.243/30stair/postorder/postorder.php?pname=postorder
//
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > graph(21); // 이진트리

void preorder(int now)
{
    // 왼쪽
    int left; scanf("%d", &left);
    graph[now].first=left;
    if(left!=-1) preorder(graph[now].first);
    // 오른쪽
    int right; scanf("%d", &right);
    graph[now].second=right;
    if(right!=-1) preorder(graph[now].second);
}

void postorder(int now)
{
    if(now==-1) return;
    postorder(graph[now].first);
    postorder(graph[now].second);
    printf("%d ", now);
}

int main(void)
{
    int root; scanf("%d", &root);
    preorder(root);
    postorder(root);
}

/*
    
*/