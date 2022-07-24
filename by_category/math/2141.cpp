// https://www.acmicpc.net/problem/2141
// 2022-07-24 23:25:53 48ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    long long total_cnt=0;
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second), total_cnt+=arr[i].second;
    
    sort(arr.begin(), arr.end());


    long long cnt=0;
    for(int i=0; i<n; i++)
    {
        cnt+=arr[i].second;
        if(cnt*2 >= total_cnt)
            return !printf("%d", arr[i].first);
    }
}

/*

오전 1:45 태식 |x-10| + |x-20|이라고 하면
오전 1:45 태식 x가 대충 15라고 했을 때
오전 1:45 태식 (x-10)+(20-x)가 되잖아
오전 1:45 태식 이상태로 미분해서 남는건
오전 1:45 태식 결국 x의 좌우 항 개수라는거지
오전 1:46 태식 그래프를 보니까 항상 뾰족하게 나오는걸보면
오전 1:46 태식 결국은 부호가 바뀌는부분이 어딘가를 찾아야 되는 것 같은데
오전 1:46 태식 그게 저 항의개수가 역전되는부분인거지
오전 1:46 태식 엄밀하게 머라고 말은 못하겠지만 그런것같아
오전 1:47 태식 그래서 정렬된상태에서의 중간값이
오전 1:47 태식 x일때
오전 1:47 태식 최소인거지

맞는 것 같음
*/