// https://www.acmicpc.net/problem/3584
// 2021-06-06 11:38:02 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> parent(n+1, -1);
        for(int i=1; i<n; i++)
        {
            int a,b; scanf("%d%d", &a,&b);
            parent[b]=a;
        }
        int node1, node2; scanf("%d%d", &node1, &node2);
        vector<int> p_list;
        while(node1!=-1)
        {
            p_list.push_back(node1);
            node1=parent[node1];
        }
        sort(p_list.begin(), p_list.end());

        while(!binary_search(p_list.begin(), p_list.end(), node2))
            node2=parent[node2];
        printf("%d\n", node2);
    }

}