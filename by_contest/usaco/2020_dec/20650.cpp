// https://www.acmicpc.net/problem/20650
// 2021-10-04 23:26:05 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> arr(7), permu(6,0);
    for(int i=0; i<7; i++) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    permu[3]=permu[4]=permu[5]=1;
    do
    {
        // get 6C3
        int num[3], used[6]={}, cnt=0;
        for(int i=0; i<6; i++) if(permu[i]) num[cnt++]=arr[i], used[i]=1;

        if(num[0]+num[1]+num[2] == arr[6])
        {
            int sum=0;
            for(int i=0; i<6; i++) if(!used[i]) sum+=arr[i];
            // a+b + b+c + a+c == 2*(a+b+c)
            if(sum!=arr[6]*2) continue;
            printf("%d %d %d", num[0], num[1], num[2]);
            return 0;
        }
    }
    while(next_permutation(permu.begin(), permu.end()));
}

/*
    
*/