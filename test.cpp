
#include<bits/stdc++.h>
using namespace std;

vector<int> tree(1,0);

void traversal(char now)
{
    if(tree[now*2]!=0)
        traversal(tree[now*2]);
    if(tree[now*2+1]!=0)
        traversal(tree[now*2+1]);
    printf("%d\n", now);
}

void insert(int target)
{
    static int count=1;
    int index=1;
    if(tree[index]>target)
        while(tree[index]>target && tree[index]!=0)
        {
            if(tree[2*index]==NULL)
            {
                tree.reserve(count);
                count*=2;
            }
            index=index*2;
        }
    else
        while(tree[index]<target && tree[index]!=0)
        {
            if(tree[2*index]==NULL)
            {
                tree.reserve(count);
                count*=2;
            }
            index=index*2;
        }
    tree[index]=target;
}

int main(void)
{
    int tmp;
    while(scanf("%d", &tmp) != EOF)
    {
        insert(tmp);
    }
    traversal(1);
    
}