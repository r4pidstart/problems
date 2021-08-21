// https://www.acmicpc.net/problem/2011
// 2021-08-21 22:00:48 0ms
#include<bits/stdc++.h>
using namespace std;


int main(void)
{
	char s[5002]={'0'};
	scanf("%s", s+1);
	int len=strlen(s);
	vector<int> dp(len+1,0);
	if(s[1]!='0') dp[0]=1;
	// s[pos]까지 이용해서 만들 수 있는 경우의 수
	for(int i=1; i<len; i++)
	{
		if(s[i]=='1')
		{
			if(s[i+1]!='\0')
				dp[i+1]+=dp[i-1];
		}
		if(s[i]=='2')
		{
			if(s[i+1]!='\0')
				if('0' <= s[i+1] && s[i+1] <= '6')
					dp[i+1]+=dp[i-1];
		}
		if(s[i]!='0')
			dp[i]+=dp[i-1];
		dp[i]=dp[i]%1000000;
	}
	printf("%d", dp[len-1]);
}

/*

*/