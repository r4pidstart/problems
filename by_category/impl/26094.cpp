// https://www.acmicpc.net/problem/26094
// 2022-12-04 02:02:42
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n,q; scanf("%d%d", &n, &q);
	list<int> lst[2];
	set<int> se;

	int front=0;
	while(q--)
	{
		int cmd; scanf("%d", &cmd);
		if(cmd == 0)
		{
			int p; scanf("%d", &p);
			lst[front].push_front(p);
		}
		else if(cmd==1)
		{
			for(auto it : lst[0])
				se.insert(it);
			for(auto it : lst[1])
				se.insert(it);
			lst[0].clear();
			lst[1].clear();
			front=0;
		}
		else if(cmd==2)
		{
			front^=1;
		}
		else if(cmd==3)
		{
			if(lst[front].size())
			{
				printf("%d\n", lst[front].front());
				lst[front].pop_front();
			}
			else
			{
				if(!se.size())
				{
					printf("%d\n", lst[front^1].back());
					lst[front^1].pop_back();
				}
				else
				{
					if(front==0)
					{
						int tmp=*(se.begin());
						printf("%d\n", tmp);
						se.erase(tmp);
					}
					else
					{
						int tmp=*(--se.end());
						printf("%d\n", tmp);
						se.erase(tmp);
					}
				}
			}
		}
	}
}

/*
	
*/