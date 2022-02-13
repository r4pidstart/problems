// https://www.acmicpc.net/problem/5397
// 2022-02-13 23:56:30 452ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int t; cin >> t;
	while(t--)
	{
		list<char> l;
		list<char>::iterator it=l.begin();
		string s; cin >> s;
		for(auto i : s)
		{
			switch (i)
			{
			case '<':
				if(it != l.begin())
					it--;
				break;
			case '>':
				if(it != l.end())
					it++;
				break;
			case '-':
				if(it != l.begin())
					it = l.erase(--it);
				break;

			default:
				l.insert(it, i);
				break;
			}
		}
		for(auto i : l)
			cout << i;
		cout << '\n';
	}
}

/*

*/