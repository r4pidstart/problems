// https://www.acmicpc.net/problem/1041
// 2021-11-17 04:17:01 0ms
#include<bits/stdc++.h>
using namespace std;

enum { A,B,C,D,E,F };
int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(6);
    for(int i=0; i<6; i++) scanf("%d", &arr[i]);
 
    // 꼭짓점
    int threeSide=min({arr[A]+arr[B]+arr[D], arr[D]+arr[B]+arr[F], 
                        arr[D]+arr[E]+arr[F], arr[D]+arr[E]+arr[A], 
                        arr[A]+arr[B]+arr[C], arr[B]+arr[C]+arr[F], 
                        arr[C]+arr[E]+arr[F], arr[C]+arr[E]+arr[A]});
    // 모서리
    int twoSide=min({arr[A]+arr[C], arr[A]+arr[D], arr[A]+arr[E], 
                    arr[A]+arr[B], arr[B]+arr[F], arr[D]+arr[E], 
                    arr[D]+arr[B], arr[D]+arr[F], arr[C]+arr[E], 
                    arr[C]+arr[B], arr[C]+arr[F], arr[F]+arr[E]});
    // 면
    int oneSide=*min_element(arr.begin(), arr.end());

    if(n==1) printf("%lld", accumulate(arr.begin(), arr.end(), 0LL)-*max_element(arr.begin(), arr.end()));
    else printf("%lld", 4LL*threeSide + 4LL*twoSide + 8LL*(n-2)*twoSide + 4LL*(n-2)*oneSide + 5LL*(n-2)*(n-2)*oneSide);
    // 모서리 n-2 * 8개, 반모서리 n-2 * 4개, 꼭짓점 4개, 반꼭짓점 4개, 면 (n-2)^2 * 5개
}

/*
    
*/