// 6-3 PICNIC
// https://algospot.com/judge/problem/read/PICNIC
// 2021-06-27 00:57:14 8ms
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > friends;

int get_count(int now_cnt, int size, int friend_cnt, int selected)
{
    if(now_cnt == size)
    {
        if(selected==((1<<friend_cnt)-1)) // 해당되는 비트가 다 켜져있을 경우
            return 1;
        else
            return 0;
    }

    bitset<10> mask=selected;
    int ret=0;
    if(!mask[friends[now_cnt].first] && !mask[friends[now_cnt].second])
    {
        int next_mask=(selected|(1<<friends[now_cnt].first))|(1<<friends[now_cnt].second);
        ret+=get_count(now_cnt+1, size, friend_cnt, next_mask); // 선택 하는경우
    }
    ret+=get_count(now_cnt+1, size, friend_cnt, selected); // 안 하는경우
    
    return ret;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        friends=vector<pair<int,int> >();
        int n,m; scanf("%d%d", &n,&m);
        for(int i=0; i<m; i++)
        {
            int a,b; scanf("%d%d", &a, &b);
            friends.push_back({a,b});
        }
        printf("%d\n", get_count(0, friends.size(), n, 0));
    }
}