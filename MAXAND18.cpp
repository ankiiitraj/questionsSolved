#include <bits/stdc++.h>
#define int long long
using namespace std;


bool compare(const pair<int, int> &pair1, const pair<int, int> &pair2)
{
	if(pair1.first > pair2.first)
		return true;
	else if(pair1.first == pair2.first and pair1.second < pair2.second)
		return true;
	return false;
}

signed main()
{
	int t; cin >> t; while(t--)
	{
		int n, k; cin >> n >> k;
		vector<int> a(n), count_of_bits(30, 0);

		for(int i = 0; i < n; ++i)
			cin >> a[i];

		for(int i = 0; i < n; ++i)
		{
			bitset<30> current_in_binary(a[i]);
			for(int i = 0; i < 30; ++i)
			{
				if(current_in_binary[i])
				{
					count_of_bits[i]++;
				}
			}
		}

		bitset<30> ans(0); vector<pair<int,int>> value_of_bits(30);

		for(int i = 0; i < 30; ++i)
		{
			value_of_bits[i] = {count_of_bits[i]*pow(2, i), i};
		}
		sort(value_of_bits.begin(), value_of_bits.end(), compare);

		int no_of_set_bits = 0;
		for(auto iterator: value_of_bits)
		{
			if(no_of_set_bits >= k)
			{
				break;
			}
			no_of_set_bits++;
			ans[iterator.second] = 1;
		}

		if(no_of_set_bits < k)
		{
			for(int i = 0; i < 30; ++i)
			{
				if(no_of_set_bits >= k)
					break;
				if(!ans[i])
				{
					no_of_set_bits++;
					ans[i] = 1;
				}
			}
		}

		cout << ans.to_ulong() << endl;
	}
	return 0;
}
