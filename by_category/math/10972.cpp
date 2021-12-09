// https://www.acmicpc.net/problem/10972
// 2021-12-10 01:51:29 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d",&n);
    vector<int> permu(n);
    for(int i=0; i<n; i++) scanf("%d", &permu[i]);
    
    if(!next_permutation(permu.begin(), permu.end()))
        printf("-1");
     else
        for(int i=0; i<n; i++) printf("%d ", permu[i]);
}

/*
    
*/