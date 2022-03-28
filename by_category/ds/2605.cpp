// https://www.acmicpc.net/problem/2605
// 2022-03-27 16:40:00 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    list<int> lst;
    for(int i=0; i<n; i++)
    {
        int k; scanf("%d", &k);
        auto cur=lst.end();
        while(k--) cur--;
        lst.insert(cur, i+1);
    }
    for(auto i : lst)
        printf("%d ", i);
}

/*
    
*/