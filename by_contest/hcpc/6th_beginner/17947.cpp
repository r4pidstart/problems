// https://www.acmicpc.net/problem/17947
// 2021-10-31 03:39:07 48ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    vector<int> used_card(4*n+1,0);

    // 버려진 카드
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        used_card[a]=used_card[b]=1;
    }

    // 본인이 뽑은 카드
    int picked_card1, picked_card2;
    scanf("%d%d", &picked_card1, &picked_card2);
    used_card[picked_card1]=used_card[picked_card2]=1;

    vector<int> cards;
    for(int i=1; i<=4*n; i++)
        if(!used_card[i]) cards.push_back(i%k);
    sort(cards.begin(), cards.end(), greater<int>());

    // 본인 점수
    int target=abs(picked_card1%k - picked_card2%k), cnt=0;

    // two pointer
    int le=0, ri=1;
    while(le<=ri)
    {
        while(ri<cards.size() and cards[le]-cards[ri] <= target) ri++;
        if(ri>=cards.size()) break;
        cnt++, le++, ri++;
    }

    printf("%d", min(m-1, cnt));
}

/*
5 6 7
11 2
3 7
5 8
14 6
12 18
13 15
9 10

20 5 7
10 2
3 7
4 8
14 6
12 20
8 12
*/