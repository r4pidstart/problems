
#include<bits/stdc++.h>
using namespace std;

vector<char> tree(2,0); 
vector<int> pos(27,0);
queue<tuple<int, int, int> > tmp;
int count=2;

void insert(int a, int b, int c)
{
    static int count=2;
    int pointer=a-'A'+1;
    if(pos[pointer]!=0)
    {
        int parent=pos[pointer];
        int size=tree.size();
        if(size-1<pointer*2)
        {
            tree.resize(size+count);
            count*=2;
        }
        if(b!='.')
            tree[parent*2]=b, pos[b-'A'+1]=parent*2;
        if(c!='.')
            tree[parent*2+1]=c, pos[c-'A'+1]=parent*2+1;
    }
    else
        tmp.push({a,b,c});
}

void print_preorder(int now)
{
    printf("%c", tree[now]);
    if(tree[now*2]!=0)
        print_preorder(now*2);
    if(tree[now*2+1]!=0)
        print_preorder(now*2+1);
}

void print_inorder(int now)
{
    if(tree[now*2]!=0)
        print_inorder(now*2);
    printf("%c", tree[now]);
    if(tree[now*2+1]!=0)
        print_inorder(now*2+1);
}

void print_postorder(int now)
{
    if(tree[now*2]!=0)
        print_postorder(now*2);
    if(tree[now*2+1]!=0)
        print_postorder(now*2+1);
    printf("%c", tree[now]);
}

int main(void)
{
    int n; scanf("%d", &n);
    tree[1]='A', pos[1]=1;
    for(int i=0; i<n; i++)
    {
        char a,b,c; scanf("\n%c %c %c", &a,&b,&c);
        insert(a,b,c);
    }
    while(!tmp.empty())
    {
        insert(get<0>(tmp.front()), get<1>(tmp.front()), get<2>(tmp.front()));
        tmp.pop();
    }

    print_preorder(1);
    printf("\n");
    print_inorder(1);
    printf("\n");
    print_postorder(1);
}