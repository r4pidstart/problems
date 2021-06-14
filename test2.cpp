
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int a)
{
    if(parent[a]<0)
        return a;
    return parent[a]=find(parent[a]);
}

int merge(int a, int b)
{
    if(a<0 || b<0)
        return 1;

    a=find(a), b=find(b);
    if(a==b)
        return 1;

    if(parent[a]>parent[b])
        swap(a,b);
    
    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

int docking(int target)
{
    if(target<1)
        return 1;
    int root=find(target);

    if(merge(target, root+parent[root]))
        return docking(root+parent[root]+1);
    return 0;
}

int main(void)
{
    int G,P; scanf("%d%d", &G, &P);
    parent.assign(G+1, -1);
    int count=0; 

    for(int i=0; i<P; i++)
    {
        int gi; scanf("%d", &gi);
        if(docking(gi)!=0)
            break;
        count++;
    }
    printf("%d", count);
}