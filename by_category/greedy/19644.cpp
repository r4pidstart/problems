// https://www.acmicpc.net/problem/19644
// 2023-07-14 04:29:22
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int l,ml,mk,cammo;
    scanf("%d%d%d%d", &l, &ml, &mk, &cammo);

    vector<int> arr(l);
    for(int i=0; i<l; i++)
        scanf("%d", &arr[i]);

    priority_queue<int, vector<int>, greater<> > pq;
    for(int i=0; i<l; i++)
    {
        while(pq.size() and pq.top()<i) pq.pop();
        if(arr[i]-(int)pq.size()*mk>mk)
        {
            if(cammo) cammo--;
            else return !printf("NO");
        }
        else pq.push(i+ml-1);
    }
    printf("YES");
}

/*

*/