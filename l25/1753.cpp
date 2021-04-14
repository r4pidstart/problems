// https://acmicpc.net/problem/1753
// 2021-04-14 17:46:18 152ms
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#define INF 0x7FFFFFFF
using namespace std;

vector<int> result(20001, INF);
priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > diijstra;
vector <pair<int,int> > dest[20001];

int main(void)
{
    int v,e,k; scanf("%d%d%d", &v,&e,&k);
    for(int i=0; i<e; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        dest[a].push_back(make_pair(b,c));
    }

    result[k]=0;
    diijstra.push(make_pair(0, k));
    while(!diijstra.empty())
    {
        int now=diijstra.top().second, dist=diijstra.top().first;
        diijstra.pop();

        for(auto it=dest[now].begin(); it!=dest[now].end(); it++)
        {
            int ndist=it->second, next=it->first;
            if(result[next]>ndist+dist)
            {
                result[next]=ndist+dist;
                diijstra.push(make_pair(result[next], next));
            }
        }
    }

    for(int i=1; i<=v; i++)
        if(result[i]==INF)
            printf("INF\n");
        else
            printf("%d\n", result[i]);
            
    return 0;
}