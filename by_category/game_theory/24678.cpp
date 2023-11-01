// https://www.acmicpc.net/problem/24678
// 2023-11-01 20:28:24
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        vector<long> arr(3);
        for(int i=0; i<3; i++)
            scanf("%ld", &arr[i]);
        sort(arr.begin(), arr.end());

        arr[2]+=arr[0], arr[1]-=arr[0];

        int flag=(arr[0]&1) ^ ((arr[1]&1) & (arr[2]&1));

        printf(flag ? "B\n":"R\n");
    }
}

/*
    돌이 한개 이하의 무더기에 있을때 게임 종료
    두 무더기를 골라 각각 돌 하나를 빼고 나머지 무더기에 돌 하나를 추가

    R        B        R        B        R        B
tc1 1 1 1 -> 0 0 2(끝)
tc2 1 3 2 -> 0 2 3 -> 1 1 2 -> 0 0 3(끝)
                            -> 0 2 1 -> 1 0 1 -> 0 1 0(끝)
          -> 0 4 1 -> 1 3 0 -> 0 2 1 -> 1 1 0 -> 0 0 1(끝)
          -> 2 2 1 -> 1 1 2 -> 0 0 3(끝)
                            -> 2 0 1 -> 1 1 0 -> 0 0 1(끝)
                   -> 3 1 0 -> 2 0 1 -> 1 1 0 -> 0 0 1(끝)

    1 2 3
->  0 1 4(1)
->  1 0 3(0)
->  0 1 2(1)
->  1 0 1(0)
->  0 1 0(1)

    0 2 100
->  1 1 99      1 1 99
->  0 0 100     2 0 98
                1 1 97
                0 0 98

    0 1 5
    1 0 4
    0 1 3
    1 0 2
    0 1 1
    1 0 0

    0 2 4
    1 1 3   1 1 3
    0 0 4   0 2 2
            1 1 1
            0 0 2

*/