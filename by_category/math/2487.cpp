// https://www.acmicpc.net/problem/2487
// 2022-01-09 04:21:44 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    unordered_set<int> us;
    vector<int> cycleSize;
    for(int i=0; i<n; i++)
    {
        if(us.find(arr[i]) == us.end())
        {
            us.insert(arr[i]);
            if(arr[i] == i+1) continue; // 사이클의 크기가 1인 경우

            int cur=arr[i], size=1;
            while(i != cur-1)
                size++, us.insert(cur), cur=arr[cur-1];
            us.insert(cur);
            cycleSize.push_back(size);
        }
    }

    int ans=1;
    for(auto i : cycleSize)
        ans=lcm(ans, i);
    printf("%d", ans);
}

/*
    
*/