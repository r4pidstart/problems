// https://www.acmicpc.net/problem/1547
// 2022-03-23 23:06:40 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr={1,0,0};
    while(n--)
    {
        int a,b; scanf("%d%d", &a,&b);
        swap(arr[a-1],arr[b-1]);
    }
    printf("%d", max_element(arr.begin(), arr.end())-arr.begin()+1);
}

/*
    
*/