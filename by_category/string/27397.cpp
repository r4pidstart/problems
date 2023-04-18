// https://www.acmicpc.net/problem/27397	
// 2023-04-18 23:59:34
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	cin.tie(nullptr)->sync_with_stdio(false);
	string s; cin >> s;
	int q; cin >> q;
	vector<int> change(256);
	iota(change.begin(), change.end(), 0);

	while(q--)
	{
		int cmd; cin >> cmd;
		if(cmd==1)
		{
			char f,t; cin >> ws >> f >> ws >> t;
			for(int& it : change)
				if(it == f) it=t;
		}
		else
		{
			for(char& c : s)
				c=change[c];

			iota(change.begin(), change.end(), 0);

			int len_max=1, prev=-1, current_len=0;
			for(char c : s)
				if(prev == c) len_max=max(len_max, ++current_len);
				else current_len=1, prev=c;
				
			cout << len_max << '\n';	
			// cout << s << '\n' << '\n';
		}
	}
}

/*
	
*/