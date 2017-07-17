// UVa 1196 - Tiling Up Blocks

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pa
{
	int l, m;
};

bool operator <(const pa & a, const pa & b)
{
	return a.l < b.l || a.l == b.l && a.m < b.m;
}

bool inside(const pa & a, const pa & b)
{
	return a.l <= b.l && a.m <= b.m;
}

int main()
{

	int n;

	cin >> n;
	while (n)
	{

		vector<pa> b;
		for (int i = 0; i < n; i++)
		{
			int l, m;
			cin >> l >> m;
			b.push_back( { l, m });
		}

		sort(b.begin(), b.end());

		unsigned long int T[10000];
		for (int i = 0; i < n; i++)
		{
			T[i] = 0;
			for (int j = i - 1; j >= 0; j--)
				if (inside(b[j], b[i]) && T[j] > T[i])
					T[i] = T[j];
			T[i]++;
		}
		cout << T[n - 1] << endl;

		cin >> n;
	}
	cout << "*" << endl;

	return 0;
}
