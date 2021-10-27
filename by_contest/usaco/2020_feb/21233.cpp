// https://www.acmicpc.net/problem/21233
// 2021-10-28 02:36:27 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    vector<int> target(n+1,0);
    for(int i=0; i<n; i++) scanf("%d", &target[i+1]);
    sort(target.begin(), target.end(), greater<int>());

    int start=target[0];
    while(start%12 != 0) start++;

    vector<int> saved_time(n,0);
    for(int i=0; i<n; i++)
    {
        // 점프하면 절약할 수 있는 시간을 각각 구하자
        int jumpF=target[i], jumpT=target[i+1];
        while(jumpF%12 != 0) jumpF--;
        while(jumpT%12 != 0) jumpT++;
        saved_time[i]=jumpF-jumpT>0 ? jumpF-jumpT:0;
    }

    sort(saved_time.begin(), saved_time.end(), greater<int>());
    printf("%d", start - accumulate(saved_time.begin(), saved_time.begin()+k-1, 0));    
}

/*
    101 100 95 85 46 0
    108 96 84 72 60

    0 0 0 36 36 
    108 

    108 - 36*2 = 36
*/