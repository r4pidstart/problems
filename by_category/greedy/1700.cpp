// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,k; scanf("%d%d", &n,&k);
	vector<int> powerstrip(n), seq(k);
	for(int i=0; i<k; i++) scanf("%d", &seq[i]);

	// 가장 나중에 사용해야 하는 것을 빼자.
	int cnt=0;
	for(int i=0; i<k; i++)
	{
		if(find(powerstrip.begin(), powerstrip.end(), seq[i]) != powerstrip.end()) continue;

		// 지금 꽃혀있는 것 중 가장 뒤에 나오는 것 찾기
		int dist=0, it=0;
		for(int j=0; j<n; j++)
		{
			auto pos=find(seq.begin()+i+1, seq.end(), powerstrip[j]);
			if(dist < pos-seq.begin() or powerstrip[j]==0)
				dist=pos-seq.begin(), it=j;
		}

		if(powerstrip[it]) cnt++;
		powerstrip[it]=seq[i];
	}
	printf("%d", cnt);
}

/*
	
*/