// https://www.acmicpc.net/problem/1419
// 2023-05-17 23:22:52
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    const vector<int> arr({0, 0, 1, 3, 2, 5,});
    int l,r,k; scanf("%d%d%d", &l, &r, &k);

    int cnt=0;
    if(k==4 and l<=12 and 12<=r) cnt--;
    l=max(k+k*(k-1)/2, l);
    while(l%arr[k] != 0) l++;
    for(int i=l; i<=r; i+=arr[k])
        cnt++;
    printf("%d", cnt);
}

/*
    k개 항의 합
    ->  k*x + k*(k-1)/2*d    
    ->  if(k==2)
            +=1
        if(k==3)
            +=3
        if(k==4)
            +=4 or +=6 -> min+4부터 +=2
        if(k==5)
            +=5
*/