// https://www.acmicpc.net/problem/18116
// 2024-03-05 22:59:59
#include"bits/stdc++.h"
using namespace std;

class Dsu
{
    private:
    public:
        vector<int> parent;
        Dsu(int size)
        {
            parent.assign(size, -1);
        }
        int find(int i)
        {
            if(parent[i]<0) return i;
            else return parent[i]=find(parent[i]);
        }
        int merge(int a, int b)
        {
            a=find(a), b=find(b);
            if(a==b) return 1;

            if(parent[a]>parent[b]) swap(a,b);
            parent[a]+=parent[b];
            parent[b]=a;
            return 0;
        }
};

int main(void)
{
    int n; scanf("%d", &n);
    Dsu dsu(1000001);
    while(n--)
    {
        char cmd; scanf(" %c", &cmd);
        if(cmd=='I')
        {
            int a,b; scanf("%d%d", &a, &b);
            dsu.merge(a, b);
        }
        else
        {
            int a; scanf("%d", &a);
            printf("%d\n", -dsu.parent[dsu.find(a)]);
        }
    }
}

/*
    
*/