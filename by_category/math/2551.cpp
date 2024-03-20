// https://www.acmicpc.net/problem/2551
// 2024-03-15 22:28:35
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    int avg=accumulate(arr.begin(), arr.end(), 0L)/n;
    long a=0, b=0;
    for(int i : arr)
        a+=(avg-i)*(avg-i), b+=(avg-i+1)*(avg-i+1);

#ifdef LOCAL
    printf("%ld %ld\n", a, b);
#endif
    
    n--;
    printf("%d %d", arr[n/2], a<=b ? avg:avg+1);
}

/*
    
*/

// int main(void)
// {
//     int n; scanf("%d", &n);
//     vector<int> arr(n);

//     srand(time(nullptr));
//     for(int i=0; i<n; i++)
//         arr[i]=rand()%10000+1;
    
//     sort(arr.begin(), arr.end());

//     for(int i=0; i<n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
//     for(int i=1; i<=10000; i++)
//     {
//         long sum=0;
//         for(int a : arr)
//             sum+=abs(a-i)*abs(a-i);

//         printf("%d: %ld\n", i, sum);
//     }
// }