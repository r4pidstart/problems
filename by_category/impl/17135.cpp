// https://www.acmicpc.net/problem/17135
// 2022-08-14 02:37:19 28ms
#include"bits/stdc++.h"
using namespace std;

inline int get_dist(pair<int,int> a, pair<int,int> b)
{
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int main(void)
{
    int n,m,d; scanf("%d%d%d", &n, &m, &d);
    vector<vector<int> > original_table(n, vector<int>(m));
    deque<pair<int,int> > initial_enemy_list;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf("%d", &original_table[i][j]);
            if(original_table[i][j])
                initial_enemy_list.push_back({i,j});
        }

    vector<int> archer_pos(m);
    archer_pos[0]=archer_pos[1]=archer_pos[2]=1;

    int max_cnt=0;
    do
    {
        deque<pair<int,int> > enemy_list=initial_enemy_list;
        vector<int> remained_archer=archer_pos;

        int elim_cnt=0;
        while(enemy_list.size())
        {
            vector<pair<pair<int, int>, int> > closest_enemy(m, {{}, INT32_MAX});

            for(auto &it : enemy_list)
            {
                for(int i=0; i<m; i++)
                    if(remained_archer[i])
                    {
                        int dist=get_dist(it, {n, i});
                        if(dist <= d and (dist < closest_enemy[i].second
                            or (dist == closest_enemy[i].second and closest_enemy[i].first.second > it.second)))
                            closest_enemy[i]={it, dist};
                    }
            }

            deque<pair<int, int> > remained_enemy;
            for(auto &it : enemy_list)
            {
                int eliminated=0;
                for(int i=0; i<m; i++)
                    if(remained_archer[i])
                        if(closest_enemy[i].second != INT32_MAX and closest_enemy[i].first == it) eliminated=1;
                if(!eliminated)
                    remained_enemy.push_back(it);
            }

            elim_cnt+=enemy_list.size()-remained_enemy.size();

            deque<pair<int,int> > new_enemy_list;
            for(auto &it : remained_enemy)
            {
                if(it.first == n-1)
                    remained_archer[it.second]=0;
                else
                    new_enemy_list.push_back({it.first+1, it.second});
            }

            enemy_list=new_enemy_list;
        }
        max_cnt=max(max_cnt, elim_cnt);
    } while (prev_permutation(archer_pos.begin(), archer_pos.end()));
    printf("%d", max_cnt);
}

/*
    
*/