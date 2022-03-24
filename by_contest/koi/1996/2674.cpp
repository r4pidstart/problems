// https://www.acmicpc.net/problem/2674
// 2022-03-25 07:57:32 0ms
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > table(22, vector<int>(22));
vector<vector<int> > h_cnt(22), v_cnt(22);
vector<int> h_cnt_sum(22), v_cnt_sum(22), for_check(22);

int check_h(int h, int v)
{
    fill(for_check.begin(), for_check.end(), 0);
    int cur=0, sum=0;
    // 0~h까지 확인하면서, 주어진 조건에 부합하지 않는 부분이 있는지 확인하기
    for(int i=0; i<=h; i++)
        if(table[v][i]) for_check[i+1]=for_check[i]+1, sum++;
        else
        {
            for_check[i+1]=0;
            if(for_check[i] and cur < h_cnt[v].size() and h_cnt[v][cur++] != for_check[i])
                return 1;
        }
    if(cur < h_cnt[v].size() and for_check[h+1] > h_cnt[v][cur])
        return 1;
    
    if(sum > h_cnt_sum[v])
        return 1;
    // 남은 공간으로 조건을 만족시킬 수 있는지 확인하기
    if(h_cnt_sum[v] > sum + (n-v - h-1))
        return 1;
    
    return 0;
}

int check_v(int h, int v)
{
    fill(for_check.begin(), for_check.end(), 0);
    int cur=v_cnt[h].size()-1, sum=0;
    // n-1 ~ v까지 확인하면서, 주어진 조건에 부합하지 않는 부분이 있는지 확인하기
    for(int i=n-1-h; i>=v; i--) // i=n-1 -> i=n-1-h? 
        if(table[i][h]) for_check[n-1-i+1]=for_check[n-1-i]+1, sum++;
        else
        {
            for_check[n-1-i+1]=0;
            if(for_check[n-1-i] and cur >= 0 and v_cnt[h][cur--] != for_check[n-1-i])
                return 1;
        }
    if(cur >= 0 and for_check[n-v] > v_cnt[h][cur])
        return 1;
    
    if(sum > v_cnt_sum[h])
        return 1;
    // 남은 공간으로 조건을 만족시킬 수 있는지 확인하기
    if(v_cnt_sum[h] > sum + (v))
        return 1;
    
    return 0;
}


int fill_table(int h, int v)
{
    if(h==n-v)
        return fill_table(0, v-1);
    if(v==-1)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-i; j++)
                printf("%d ", table[i][j]);
            printf("\n");
        }
        exit(0);
    }

    table[v][h]=0;
    if(!check_h(h,v) and !check_v(h,v))
        fill_table(h+1, v);

    table[v][h]=1;
    if(!check_h(h,v) and !check_v(h,v))
        fill_table(h+1, v);
    table[v][h]=0;
    return 0;
}

int main(void)
{
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        int n; scanf("%d", &n);
        while(n--)
        {
            int a; scanf("%d", &a);
            h_cnt[i].push_back(a);
            h_cnt_sum[i]+=a;
        }
    }
    for(int i=0; i<n; i++)
    {
        int n; scanf("%d", &n);
        while(n--)
        {
            int a; scanf("%d", &a);
            v_cnt[i].push_back(a);
            v_cnt_sum[i]+=a;
        }
    }

    fill_table(0, n-1);
    printf("No Answer");
}

/*
    
*/