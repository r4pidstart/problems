// https://www.acmicpc.net/problem/20301
// 2022-07-19 01:04:53
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k,m; scanf("%d%d%d", &n, &k, &m);

    deque<int> arr(n);
    for(int i=0; i<n; i++)
        arr[i]=i+1;
    
    int dir=0, cnt=0, mov=k-1;

    while(arr.size())
    {
        for(int i=0; i<k-1; i++)
        {
            if(dir == 0)
            {
                arr.push_back(arr.front());
                arr.pop_front();
            }
            else
            {
                arr.push_front(arr.back());
                arr.pop_back();
            }
        }
        
        if(dir == 0)
            printf("%d\n", arr.front()), arr.pop_front();
        else
            printf("%d\n", arr.back()), arr.pop_back();

        cnt++;
        if(cnt%m == 0)
            dir^=1;
    }
}

/*
    
*/