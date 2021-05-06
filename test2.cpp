
#include<bits/stdc++.h>
using namespace std;

vector<int> tree(2,0);

void traversal(char now)
{
    if(now*2<tree.size()-1)
        traversal(now*2);
    if(now*2+1<tree.size()-1)
        traversal(now*2+1);
    if(tree[now]!=0)
        printf("%d\n", tree[now]);
}

void insert(int target)
{
    static int count=2;
    int index=1;
    while(tree[index]!=0)
    {
        if(tree[index]>target)
        {
            if(2*index>=tree.size()-1)
            {
                tree.resize(tree.size()+count);
                count*=2;
            }
            index=index*2;
        }
        else
        {
            if(2*index>=tree.size()-1)
            {
                tree.resize(tree.size()+count);
                count*=2;
            }
            index=index*2+1;
        }
    }
    tree[index]=target;
}

int main(void)
{
    int tmp;
    while(scanf("%d", &tmp) != EOF)
        insert(tmp);
    printf("\n");
    traversal(1);
}