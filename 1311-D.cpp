// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj
//                      Problem Name    :    Three Integers
//         		Problem Link : https://codeforces.com/contest/1311/problem/D
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
		int a, b, c, score = INT_MAX, A, B, C;
		cin >> a >> b >> c;

		for(int i = 1; i <= 30001; ++i){
			for(int j = i; j <= 30001; j += i){
				for(int k = j; k <= 30001; k += j){
					int temp = abs(a - i) + abs(b - j) + abs(c - k);
					if(temp < score){
						A = i, B = j, C = k;
						score = temp;
					}
				}
			}
		}
		cout << score << endl << A << " " << B << " " << C << endl;

	}

	return 0;

}