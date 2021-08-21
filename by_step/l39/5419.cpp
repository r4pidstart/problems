// https://www.acmicpc.net/problem/5419
// 2021-08-22 01:36:07 684ms
#include<bits/stdc++.h>
using namespace std;

vector<int> seg_tree;
vector<pair<int,int> > x_axis, y_axis;

#define mid (s+e)/2
int seg_update(int now, int s, int e, int t)
{
	if(!(s<=t && t<=e)) return seg_tree[now];
	if(s==e) return ++seg_tree[now];
	return seg_tree[now]=seg_update(now*2, s, mid, t)+seg_update(now*2+1, mid+1, e, t);
}

int seg_find(int now, int s, int e, int l, int r)
{
	if(e<l || r<s) return 0;
	if(l<=s && e<=r) return seg_tree[now];
	return seg_find(now*2, s, mid, l, r)+seg_find(now*2+1, mid+1, e, l, r);
}

bool compy(const pair<int,int>& a, const pair<int,int>& b)
{
	return a.second>b.second;
}

bool compx(const pair<int,int>& a, const pair<int,int>& b)
{
	if(a.first==b.first)
		return a.second>b.second;
	return a.first<b.first;
}

int main(void)
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n; scanf("%d", &n);
		seg_tree.assign(4*n,0);
		x_axis.assign(n,{});
		for(int i=0; i<n; i++)
			scanf("%d%d", &x_axis[i].first, &x_axis[i].second);

		y_axis=x_axis;

		sort(y_axis.begin(), y_axis.end(), compy);
		sort(x_axis.begin(), x_axis.end(), compx);

		long long ans=0;
		for(int i=0; i<n; i++)
		{
			// 트리에 들어있는 정점의 x좌표는 모두 현재 정점의 x좌표보다 작거나 같음.
			int target=lower_bound(y_axis.begin(), y_axis.end(), x_axis[i], compy)-y_axis.begin();
			ans+=seg_find(1, 0, n-1, 0, target);
			// x축이 작은 순으로 y축을 트리에 집어넣음
			seg_update(1, 0, n-1, target);
		}
		printf("%lld\n", ans);
	}
}

/*

*/