// https://www.acmicpc.net/problem/11657
// 2021-04-17 23:45:33 12ms

// 2) 재채점 되는 과정에서 맞았습니다에서 결과가 출력초과로 바뀌게 되어서 확인해봤더니,
//    입력이 다음과 같이 주어지는 경우가 있는 것 같다.
//    N = 500 이고, M = 6000 일 때, 6000개의 간선이
//    1 → 2 로 -10000 만큼의 비용이 든다.
//    2 → 1 로 -10000 만큼의 비용이 든다.
//    이 2개로만 6000개가 채워지는 입력이 있는 것 같습니다.
//    위의 경우는 당연하게 음의사이클이 발생함에도, 그 음의사이클의 수치가 int형의 범위를 넘어서서 음의 사이클이
//    발생하지 않는다고 판단되는 문제가 있어서, 자료형을 long long을 이용해서 구현해주었습니다.
// 출처: https://yabmoons.tistory.com/380 [얍문's Coding World..]
#include<iostream>
#include<vector>
#define INF 0x7FFFFFFF
using namespace std;

vector<pair<int,int> > dest[501];
vector<long long> dist(501, INF);

int main(void)
{
    int v,e; scanf("%d%d", &v,&e);
    for(int i=1; i<=e; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        dest[a].push_back({b,c});
    }

    dist[1]=0;
    for(int i=0; i<v-1; i++)
        for(int now=1; now<=v; now++)
            for(auto it=dest[now].begin(); it!=dest[now].end(); it++)
            {
                if(dist[now]==INF) // 출발지가 INF라면
                    continue;
                if(dist[it->first] > dist[now]+it->second)
                    dist[it->first]=dist[now]+it->second;
            }
        
    // 재탐색시 업데이트 되면 -1
    for(int i=0; i<v-1; i++)
        for(int now=1; now<=v; now++)
            for(auto it=dest[now].begin(); it!=dest[now].end(); it++)
            {
                if(dist[now]==INF) // 출발지가 INF라면
                    continue;
                if(dist[it->first] > dist[now]+it->second)
                {
                    printf("-1");
                    return 0;
                }
            }

    for(int i=2; i<=v; i++)
        printf("%lld\n", dist[i]==INF ? -1:dist[i]);
    return 0;
}