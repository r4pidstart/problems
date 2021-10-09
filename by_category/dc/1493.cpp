// https://www.acmicpc.net/problem/1493
// 2021-10-10 03:25:40 268ms
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > cube;
// size, cnt

int dc(int l, int w, int h)
{
	int ret=0;
	for(auto& it : cube)
	{
		if(it.first<=l && it.first<=w && it.first<=h)
			if(it.second)
			{
				it.second--;
				ret+=dc(l, w, h-it.first);
				ret+=dc(l-it.first, w, it.first);
				ret+=dc(it.first, w-it.first, it.first);
				return ret+1;
			}
	}

	if(!l || !w || !h) return 0; // 채울 필요 없는 경우
	// 채울 수 없는 경우
	printf("-1");
	exit(0);
}

int main(void)
{
	int l,w,h; scanf("%d%d%d", &l, &w, &h);
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a,b; scanf("%d%d", &a, &b);
		cube.push_back({pow(2, a), b});
	}

	// 큰 것부터 쓸 수 있도록 정렬
	sort(cube.rbegin(), cube.rend());
	printf("%d", dc(l,w,h));
}

/*
	
*/