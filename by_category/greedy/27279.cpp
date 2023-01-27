// https://www.acmicpc.net/problem/27279
// 2023-01-28 05:21:11
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n,m; scanf("%d%d", &n, &m);
	vector<int> soldier(n), work(m);
	for(int i=0; i<n; i++)
		scanf("%d", &soldier[i]);
	for(int i=0; i<m; i++)
		scanf("%d", &work[i]);

	sort(soldier.begin(), soldier.end());
	sort(work.begin(), work.end());

	int idx=0;
	for(int i=0; i<n; i++)
	{
		if(idx<m and soldier[i] > idx)
			work[idx]--;
		if(idx<m and !work[idx])
			idx++;
	}
	printf("%s", idx==m ? "YES":"NO");
}

/*
	
*/