* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
							Author : Ankit Raj 
		Problem Link : https://www.codechef.com/FEB20B/problems/CHEFRAIL/
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define F first
#define S second
using namespace std;

#define MAXN 1000001

int spf[MAXN];

void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)
		spf[i] = i;

	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j < MAXN; j += i)

				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

int getFactorization(int x)
{
	if(x == 1)
		return 1;
	vector<int> ret;
	while (x != 1)
	{
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	int cnt = 1, ans = 1;
	for (int i = 0, j = 1; j < ret.size(); ++j, ++i)
	{
		if (ret[i] != ret[j])
		{
			if (cnt & 1)
				ans *= ret[i];
			cnt = 0;
		}
		cnt++;
	}
	if (cnt & 1)
		ans *= ret[ret.size() - 1];
	return ans;
}


int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	sieve();
	int t; cin >> t; while (t--)
	{
		int n, m, ans = 0, cnt1 = 0;
		cin >> n >> m;
		int x[n], y[m];
		bool xzero = 0, yzero = 0, x1p = 0, x1n = 0, y1p = 0, y1n = 0;
		map <int, int> xsq, ysq;
		set <int> sqXP, sqXN, sqYP, sqYN;
		map <int, vector<int>> mapxp, mapyp;
		vector<int> xp, yp, xn, yn;

		for (int i = 0; i < n; ++i)
		{
			cin >> x[i];
			if (x[i] != 0)
			{
				xsq[x[i]*x[i]]++;
				if (x[i] > 0)
					xp.pb(x[i]);
				else
					xn.pb(x[i]);
			}
			else
				xzero = 1;
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> y[i];
			if (y[i] != 0)
			{
				ysq[y[i]*y[i]]++;
				if (y[i] > 0)
					yp.pb(y[i]);
				else
					yn.pb(y[i]);
			}
			else
				yzero = 1;
		}

		for (int i = 0; i < xp.size(); ++i)
		{
			int temp;
			
			{
				temp = getFactorization(xp[i]);
				mapxp[temp].pb(i);
			}
			
		}
		for (int i = 0; i < yp.size(); ++i)
		{
			int temp;
			
			{
				temp = getFactorization(yp[i]);
				mapyp[temp].pb(i);
			}
		}

		for (auto item : xn)
		{
			int temp = getFactorization(-1 * item);
			if (mapxp.find(temp) != mapxp.end())
			{
				for (auto itr : mapxp[temp])
				{
					ans += ysq[-1 * item * xp[itr]];
				}
			}
		}
		for (auto item : yn)
		{
			int temp = getFactorization(-1 * item);
			if (mapyp.find(temp) != mapyp.end())
			{
				for (auto itr : mapyp[temp])
				{
					ans += xsq[-1 * item * yp[itr]];
				}
			}
		}

		if (xzero or yzero)
			ans += (xp.size() * (yp.size() + yn.size()) + xn.size() * (yp.size() + yn.size()));
		cout << ans << endl;
	}
}
