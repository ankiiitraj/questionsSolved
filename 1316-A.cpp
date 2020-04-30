// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj										  //
//                      Problem Name    :    Grade Allocation                             //
//         		Problem Link : https://codeforces.com/contest/1316/problem/A              //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
// const int N = 100005;

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while (t--)
	{
		int n, m, sum = 0;
		long double avg = 0.0;
		cin >> n >> m;
		vector<int> a(n +1);
		for (int i = 1; i < n +1; ++i)
			cin >> a[i], sum += a[i];
		for(int i = 2; i <= n; ++i)
		{
			if(a[1] + a[i] >= m){
				a[1] = m;
				break;
			}
			a[1] += a[i];
		}
		cout << a[1] << endl;


	}
}