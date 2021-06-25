
#include<bits/stdc++.h>
using namespace std;

vector<int> j;
int dc(int lo, int hi)
{
    // nlogn
    if(lo==hi)
        return j[hi];

    int mid=(lo+hi)/2;
    // lo~mid에 최대값, mid를 포함한 최대값, mid+1~hi에 최대값
    int lomid=INT32_MIN, midhi=INT32_MIN, tmpsum=0;
    for(int i=mid; i>=lo; i--)
    {
        tmpsum+=j[i];
        lomid=max(lomid, tmpsum);
    }
    tmpsum=0;
    for(int i=mid; i<=hi; i++)
    {
        tmpsum+=j[i];
        midhi=max(midhi, tmpsum);
    }

    return max({lomid+midhi-j[mid], dc(lo, mid), dc(mid+1, hi)});
}

int main(void)
{
    int n; scanf("%d", &n);
    j.assign(n+1, 0);
    for(int i=1; i<=n; i++)
        scanf("%d", &j[i]);
    printf("%d", dc(1, n));
}