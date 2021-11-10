// https://www.acmicpc.net/problem/17830
// 2021-11-11 04:20:49 F
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n; scanf("%d", &n);
		int minBit=0, minCnt=0, maxBit=0, maxCnt=0;
		for(int i=n; i>0; i--)
		{
			char c; scanf(" %c", &c);
			if(c=='?') maxBit=max(maxBit, i), maxCnt++;
			else if (c=='1') maxBit=max(maxBit, i), minBit=max(minBit, i), minCnt++, maxCnt++;
		}
		// 1이 두개 이상 존재하면 비트 자리수만큼 더하고, 한개 존재하면 비트 자리수-1을 더함
		printf("%d %d\n", maxBit ? (n+maxBit + (maxCnt>1 ? 0:-1)):1, minBit ? (n+minBit + (minCnt>1 ? 0:-1)):1);
	}
}

/*
	
*/