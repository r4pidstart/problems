// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n,m; scanf("%d%d", &n, &m);
	vector<int> first(n), second(n);
	int line_cnt=0;
	priority_queue<pair<int,int> > pq_target, pq_origin;
	for(int i=0; i<n; i++)
	{
		scanf("%d", &first[i]);
		pq_origin.push({first[i], i});
	}
	for(int i=0; i<n; i++)
	{
		scanf("%d", &second[i]);
		pq_target.push({second[i], i});
	}

	// 먼저 타겟이 큰 거에 몰기
	int biggest_target=pq_target.top().second;

	vector<pair<int,int> > q1, q2;
	//{갯수, 번호}

	while(pq_origin.size())
	{
		auto [cnt, target]=pq_origin.top();
		pq_origin.pop();
		if(cnt==0 || target==biggest_target) 
			continue; // 0짜리 하면 안댐
		//printf("+ %d %d\n", n, cnt);
		q1.push_back({biggest_target, cnt});
	}	

	// 제일 큰 거에서 타겟이 가장 큰 걸 하나씩 뽑으면서
	while(pq_target.size())
	{
		auto [cnt, target]=pq_target.top();
		pq_target.pop();
		if(cnt==0 || target==biggest_target) continue;
		q2.push_back({target, cnt});

	}
	// for(int i=0; i<n-1; i++)
	// {
	// 	if(second[i] == 0) continue; // 0하며 나댄ㄴㄷㄹㄴㄹ댜
	// 	//printf("- %d %d\n", n, second[i]);
	// 	q2.push_back({n, second[i]});
	// }

	printf("%d\n", q1.size()+q2.size());
	for(auto it : q1)
		printf("+ %d %d\n", it.first+1, it.second);
	for(auto it : q2)
		printf("+ %d %d\n", it.first+1, it.second);
}

/*
	
*/