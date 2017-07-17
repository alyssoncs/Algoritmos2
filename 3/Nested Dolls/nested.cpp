#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;


pair<int, int> doll[20003];
vector<pair<int, int> > v;
int N;

bool fn(const pair<int, int>& L, const pair<int, int>& R)
{
	if (L.first == R.first)
		return L.second > R.second;
	else
		return L.first < R.first;
}

void solve()
{
	sort(doll, doll + N, fn);
	v.clear();
	v.push_back(doll[N - 1]);
	for (int i = N - 2; i >= 0; --i)
	{
		int hi = v.size() - 1, lo = 0, mid;
		while (lo <= hi)
		{
			mid = (hi + lo) / 2;
			if (v[mid].first == doll[i].first
			    || v[mid].second <= doll[i].second)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		if (lo == v.size())
			v.push_back(doll[i]);
		else
		{
			v[lo].second = doll[i].second;
			v[lo].first = doll[i].first;
		}
	}
	printf("%d\n", (int)v.size());
}

int main()
{
	int tc, u, v;

	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d", &u, &v);
			doll[i] = make_pair(u, v);
		}
		solve();
	}
	return 0;
}
