// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//                               Author : Ankit Raj 
//                      Problem Name    :    Maximum Path Sum - I
//         		Problem Link : https://projecteuler.net/problem=18
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
	vector <int> a[100];
	int temp;
	for(int i = 0; i < 100; ++i){
		for(int j = 0; j < i +1; ++j){
			cin >> temp, a[i].push_back(temp);
		}
	}

	for(int i = 1; i < 100; ++i) {
		for(int j = 0; j < i +1; ++j) {
			if(j == i)
				a[i][j] += a[i -1][j -1];
			else if(j == 0)
				a[i][j] += a[i -1][j];
			else
				a[i][j] += max(a[i -1][j], a[i -1][j -1]);
		}
	}
	int ans = INT_MIN;
	for(int i = 0; i < 100; ++i)
		ans = max(ans, a[99][i]);
	cout << ans << endl;
}