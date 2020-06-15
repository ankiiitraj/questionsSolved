#include <bits/stdc++.h>
#include <time.h>
#define int long long int
using namespace std;
int n;

int median(int l, int r)
{
	int res = l + (r - l)/2;
	return res;
}

bool removing_some_ranges_technique(int l, int r)
{
	char c;
	if(l == r)
	{
		cout << l << endl;
		cin >> c;
		if(c == 'E')
			return 1;
		return 0;
	}else if(l +1 == r)
	{
		cout << l << endl;
		cin >> c;
		if(c == 'E')
			return 1;
		cout << r << endl;
		cin >> c;
		if(c == 'E')
			return 1;
		return 0;
	}

	int mid = median(l, r);
	cout << mid << endl;
	cin >> c;
	if(c == 'E')
		return 1;
	else if(c == 'L')
	{
		int mid_dash = median(mid +1, r);
		cout << mid_dash << endl;
		cin >> c;
		if(c == 'E')
			return 1;
		else if(c == 'L')
		{
			r = mid_dash -1;
			return removing_some_ranges_technique(l, r);
		}
		else
		{
			bool f = removing_some_ranges_technique(mid_dash +1, r);
			if(f)
			{
				return 1;
			}
			else
			{
				return removing_some_ranges_technique(l, mid -1);
			}
		}
		
	}
	else
	{
		int mid_dash = median(l, mid -1);
		cout << mid_dash << endl;
		cin >> c;
		if(c == 'E')
			return 1;
		else if(c == 'G')
		{
			l = mid_dash +1;
			return removing_some_ranges_technique(l, r);
		}
		else
		{
			bool f = removing_some_ranges_technique(l, mid_dash -1);
			if(f)
			{
				return 1;
			}
			else
			{
				return removing_some_ranges_technique(mid +1, r);
			}
		}
	}
}

bool asking_queries_on_edges_technique()
{
	int l = 1, r = n, mid, cnt = 0;
	char c;
	while(1)
	{
		if(cnt&1)
		{
			cout << l << endl;
			cin >> c;
			++l;
			if(c == 'L')
			{
				break;
			}
		}
		else
		{
			cout << r << endl;
			cin >> c;
			--r;
			if(c == 'G')
			{
				break;
			}
		}
		cnt++;
		if(c == 'E')
		{
			return 0;
		}
	}
	while(l <= r)
	{
		mid = l + (r - l)/2;
		cout << mid << endl;
		cin >> c;
		if(c == 'E')
		{
			return 0;
		}
		if(c == 'G')
		{
			l = mid +1;
		}
		else
		{
			r = mid -1;
		}
		while(1)
		{
			int r1 = rand()%l +1;
			if(r1&1)
			{
				r1 = rand()%(n - r) + r +1;
				cout << r1 << endl;
				cin >> c;
				if(c == 'G')
				{
					break;
				}
			}
			else
			{
				cout << r1 << endl;
				cin >> c;
				if(c == 'L')
				{
					break;
				}
			}
			if(c == 'E')
			{
				return 0;
			}
		}

	}
	return 0;
}

int32_t main()
{
	cin >> n;
	srand(time(NULL));
	int random = rand()%2;
	if(random&1)
	{
		removing_some_ranges_technique(1, n);
	}
	else
	{
		asking_queries_on_edges_technique();
	}
	return 0;
}