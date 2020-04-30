// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj
//                      Problem Name    :    Wierd Sort
//         		Problem Link : https://codeforces.com/contest/1311/problem/B
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t;cin >> t;while (t--) {
		int n, m, temp;
		cin >> n >> m;
		int a[n], flag = 0;
		set <int> p;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < m; ++i)
			cin >> temp, p.insert(temp);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(a[j] > a[j +1] and p.find(j +1) != p.end()){
					temp = a[j];
					a[j] = a[j +1];
					a[j +1] = temp;
				}
			}
		}
		for(int i = 0; i < n; ++i){
			if(a[i] > a[i +1]){
				flag = 1;
				break;
			}
		}
		if(flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}



}