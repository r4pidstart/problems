// https://www.acmicpc.net/problem/11729
// 2021-10-07 04:24:43 176ms
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > ans;
void hanoi(int quantity, int from, int to, int via)
{
    if(quantity==1)
        ans.push_back({from, to});
    else
    {
        hanoi(quantity-1, from, via, to); // n-1개를 빈 칸에 옮기고
        hanoi(1, from, to, via); // 1개를 목적지에 옮기고
        hanoi(quantity-1, via, to, from); // n-1개를 다시 목적지로 옮긴다.
    }
}

int main(void)
{
    int n; scanf("%d", &n);
    hanoi(n, 1, 3, 2);
    printf("%d\n", (int)ans.size());
    for(auto& it : ans)
        printf("%d %d\n", it.first, it.second);
}

/*
    
*/