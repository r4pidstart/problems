// https://www.acmicpc.net/problem/2470
// 2021-04-21 07:33:00 24ms
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    int first=0, second=n-1;
    int ans[2], difference=0x7FFFFFFF;
    while(first<second)
    {
        int sum=arr[first]+arr[second];
        if(abs(sum)<difference)
        {
            difference=abs(sum);
            ans[0]=arr[first];
            ans[1]=arr[second];
        }
        if(sum==0)
        {
            ans[0]=arr[first];
            ans[1]=arr[second];
            break;
        }
        else if(sum>0)
        {
            second--;
        }
        else // sum<0
        {
            first++;
        }
    }
    printf("%d %d", ans[0], ans[1]);
}
