// https://www.acmicpc.net/problem/17293
// 2023-08-13 04:28:57
#include"bits/stdc++.h"
using namespace std;

string func(int n)
{
    if(n==0) return "no more bottles";
    else if(n==1) return "bottle";
    else return "bottles";
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        if(n-i-1)
            printf("%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d %s of beer on the wall.\n\n",
                n-i, n-i, n-i-1, func(n-i-1).c_str());
        else
            printf("1 bottle of beer on the wall, 1 bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall.\n\n");
    }
    printf("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, %d %s of beer on the wall.",
            n, func(n).c_str());
}

/*
    
*/