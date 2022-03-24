// https://www.acmicpc.net/problem/5597
// 2022-03-24 23:58:51 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> arr(30, 0);
    for(int i=0; i<28; i++)
    {
        int a; scanf("%d", &a);
        arr[a-1]++;
    }

    for(int i=0; i<30; i++)
        if(!arr[i]) printf("%d\n", i+1);
}

/*
    
*/