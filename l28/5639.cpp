// https://www.acmicpc.net/problem/5639
// 2021-05-06 20:51:54 92ms
#include<bits/stdc++.h>
using namespace std;


typedef struct node
{
    int data;
    node *bigger;
    node *smaller;
} node;

node *root=NULL;

void insert(int target)
{
    node *new_node = new node;
    new_node->data=target, new_node->bigger=NULL, new_node->smaller=NULL;
    node *index=root;
    if(root==NULL)
    {
        root=new_node;
        return;
    }
    while(true)
    {
        if(index->data>target)
            if(index->smaller!=NULL)
                index=index->smaller;
            else
            {
                index->smaller=new_node;
                break;
            }
        else
            if(index->bigger!=NULL)
                index=index->bigger;
            else
            {
                index->bigger=new_node;
                break;
            }
    }
}

void traversal(node *now)
{
    if(now->smaller != NULL)
        traversal(now->smaller);
    if(now->bigger != NULL)
        traversal(now->bigger);
    printf("%d\n", now->data);
}

int main(void)
{
    int tmp;
    while(scanf("%d", &tmp) != EOF)
        insert(tmp);
    traversal(root);
}