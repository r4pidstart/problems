
#include<bits/stdc++.h>
using namespace std;
#define it vector<int>::iterator

int main(void)
{
    vector<int> tree;
    tree.reserve(5);
    tree[3]=1;
    printf("%d,%d,%d,%d", tree[0],tree[2],tree[3],tree[4]);
    if(tree.at(2)==out_of_range)
        printf("test");
}