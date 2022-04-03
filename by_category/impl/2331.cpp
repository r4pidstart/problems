// https://www.acmicpc.net/problem/2331
// 2022-04-03 16:27:48 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,p; scanf("%d%d", &a, &p);
    unordered_map<int, int> visited;
    vector<int> arr={a};
    visited[a]++;
    int cycle_cnt=0;
    while(true)
    {
        int tmp=arr.back();
        int tmp2=0;
        while(tmp)
        {
            tmp2+=pow(tmp%10, p);
            tmp/=10;
        }
        if(visited[tmp2] == 2) 
            break;
        if(visited[tmp2] == 1)
            cycle_cnt++;

        visited[tmp2]++;
        arr.push_back(tmp2);
    }
    printf("%d", (int)visited.size()-cycle_cnt);
}

/*
    
*/