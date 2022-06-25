// https://www.acmicpc.net/problem/25308
// 2022-06-25 23:33:36 4ms
#include"bits/stdc++.h"
using namespace std;

double get_dist(double x1, double x2, double y1, double y2)
{
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

int main(void)
{
    vector<int> arr(8);
    for(int i=0; i<8; i++)
        scanf("%d", &arr[i]);
    vector<int> permu={0,1,2,3,4,5,6,7};

    int ans=0;
    do
    {
        int flag=1;
        for(int i=0; i<8; i++)
        {
            double prev=arr[permu[(i+7)%8]], next=arr[permu[(i+1)%8]], now=arr[permu[i]];

            double tmp=(prev / (1 + (prev/next)));
            double dist_to_intersection=get_dist(0, tmp, 0, (-prev/next)*tmp + prev);
            if(dist_to_intersection > now*now)
                flag=0;
        }
        ans+=flag;
    } while (next_permutation(permu.begin(), permu.end()));
    printf("%d", ans);
}

/*
    
*/