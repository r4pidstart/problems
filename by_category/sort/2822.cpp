// https://www.acmicpc.net/problem/2822
// 2022-03-25 00:32:58 0ms 
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<pair<int, int> > arr(8);
    for(int i=0; i<8; i++)
    {
        scanf("%d", &arr[i].first);
        arr[i].second=i+1;
    }
    sort(arr.begin(), arr.end(), greater<pair<int,int> >());
    printf("%d\n",arr[0].first+arr[1].first+arr[2].first+arr[3].first+arr[4].first);
    sort(arr.begin(), arr.begin()+5, [](auto a, auto b){ return a.second < b.second; });
    for(int i=0; i<5; i++)
        printf("%d ", arr[i].second);
}

/*
    
*/