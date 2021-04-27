#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> arr({1,2,5,7,9});
    printf("%d\n", upper_bound(arr.begin(), arr.end(), 3)-arr.begin());
    printf("%d", lower_bound(arr.begin(), arr.end(), 6)-arr.begin());

}