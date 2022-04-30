// https://www.acmicpc.net/problem/7573
// 2022-04-30 04:57:39 568ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,l,m; scanf("%d%d%d", &n, &l, &m);
	vector<vector<bool> > table(n+1, vector<bool>(n+1));
	vector<pair<int,int> > fishes(m);
	for(int i=0; i<m; i++)
	{
		scanf("%d%d", &fishes[i].first, &fishes[i].second);
		table[fishes[i].first][fishes[i].second]=1;
	}

	int ans=0;
	for(auto fish1 : fishes)
		for(auto fish2 : fishes)
		{
			pair<int,int> fish={min(fish1.first, fish2.first), min(fish1.second, fish2.second)};
			// 만들 수 있는 그물들
			for(int w=1; l-w-w>=2; w++)
			{
				int tmp=0, h=(l-w-w)/2;
				for(int x=fish.first, wl=min(n, x+w); x<=wl; x++)
					for(int y=fish.second, hl=min(n, y+h); y<=hl; y++)
						if(table[x][y]) tmp++;
				ans=max(tmp, ans);
			}
		}
	printf("%d", ans);
}

/*
	
*/