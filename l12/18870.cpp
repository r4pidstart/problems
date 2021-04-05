// https://www.acmicpc.net/problem/18870
// 2021-04-05 22:25:08 636ms
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int num[n];
    vector<int> sorted(n);

    for(int i=0; i<n; i++)
    {    
        int tmp; scanf("%d", &tmp);
        sorted[i]=tmp;
        num[i]=tmp;
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); 

    for(int i=0; i<n; i++)
        printf("%d ", lower_bound(sorted.begin(), sorted.end(), num[i])-sorted.begin());
}