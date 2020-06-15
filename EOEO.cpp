#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main()
{
	int t; 
	cin >> t; 
	while(t--)
	{
		int n, res;
		cin >> n;
		if(n%2 == 1)
		{
			res = n/2;
			cout << res << endl;
		}
		else
		{
			res = pow(2, (int)log2(n & -n) + 1);
			res = n/res;
			cout << res << endl;
		}
	}
}