// https://www.acmicpc.net/problem/21921
// 2023-10-13 02:53:16
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int max_people_cnt=0, max_duration_cnt=0;
    int l=0, r=0, sum=0;
    for(int i=0; i<k; i++)
        sum+=arr[r++];
    if(sum)
        max_people_cnt=sum, max_duration_cnt=1;
    while(r<n)
    {
        sum-=arr[l++];
        sum+=arr[r++];
        if(sum > max_people_cnt)
            max_people_cnt=sum, max_duration_cnt=1;
        else if(sum == max_people_cnt)
            max_duration_cnt++;
    }
    if(!max_people_cnt)
        printf("SAD");
    else
        printf("%d\n%d\n", max_people_cnt, max_duration_cnt);
}

/*

*/