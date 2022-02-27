// https://www.acmicpc.net/problem/21133
// 2022-02-28 02:40:42 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> even, odd;
    for(int i=2; i<=n; i+=2) //even
        even.push_back(i);
    for(int i=1; i<=n; i+=2) //odd
        odd.push_back(i);

    if(n%6 == 2)
    {
        // swap 1, 3 and move 5 to the end
        swap(odd[0], odd[1]);
        odd.erase(odd.begin()+2);
        odd.push_back(5);
    }
    else if(n%6 == 3)
    {
        // move 2 to the end, move 1,3 to the end
        even.erase(even.begin());
        even.push_back(2);
        odd.erase(odd.begin());
        odd.erase(odd.begin());
        odd.push_back(1);
        odd.push_back(3);
    }
    for(auto i : even)
        printf("%d\n", i);
    for(auto i : odd)
        printf("%d\n", i);
}

/*

*/