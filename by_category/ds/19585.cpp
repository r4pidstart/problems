// https://www.acmicpc.net/problem/19585
// 2023-04-14 22:45:10
#include"bits/stdc++.h"
using namespace std;

template <int char_cnt>
class Trie
{
	private:
		template <typename T>
		int char_to_idx(T a)
		{
			/* ascii non-capital alpha */
			return a-'a';
			/* ascii capital alpha */
			// return a-'A';
		}	
		map<int, Trie *> next;
		int finished;
	public:
		static vector<int> idxs;
		Trie()
		{
			// next.assign(char_cnt, nullptr);
			finished=0;
		}
		~Trie()
		{
			// for(Trie * it : next) 
			// 	free(it);
		}
		int insert(const string& s, size_t idx=0)
		{
			if(s.size()==idx) // last char
				return finished++;

			int next_idx=char_to_idx(s[idx]);
			// if(next[next_idx]) next[next_idx]=new Trie<char_cnt>();
			if(next.find(next_idx) == next.end()) next[next_idx]=new Trie<char_cnt>();
			return next[next_idx]->insert(s, idx+1);
		}
		int find(const string& s, size_t idx=0)
		{
			if(finished) idxs.push_back(idx);
			if(s.size() == idx) return 0;
			// if(s.size()==idx) // last char
			// {
			// 	return finished;
			// }

			int next_idx=char_to_idx(s[idx]);
			// if(!next[next_idx]) return 0;
			if(next.find(next_idx) == next.end()) return 0;
			return next[next_idx]->find(s, idx+1);
		}
};

template<int char_cnt>
vector<int> Trie<char_cnt>::idxs;

int main(void)
{
#ifdef LOCAL
#endif
	cin.tie(nullptr)->sync_with_stdio(false);

	Trie<26> trie;
	int c,n; cin >> c >> n;
	for(int i=0; i<c; i++)
	{
		string s; cin >> s;
		trie.insert(s);
	}
	set<string> se;
	for(int j=0; j<n; j++)
	{
		string s; cin >> s;
		se.insert(s);
	}

	int q; cin >> q;
	while(q--)
	{
		Trie<26>::idxs.clear();
		Trie<26>::idxs.reserve(1000);

		string s; cin >> s;
		trie.find(s);

		int flag=0;
		for(auto it : Trie<26>::idxs)
		{
			// cout << it << '\n';
			if(se.find(s.substr(it)) != se.end())
			{
				// cout << s.substr(0, it) << " " << s.substr(it) << '\n';
				flag=1; 
				break;
			}
		}
		cout << (flag ? "Yes":"No") << '\n';
	}
}

/*
	
*/