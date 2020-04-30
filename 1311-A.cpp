// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj
//                      Problem Name    :    Add Odd or Substract Even
//         		Problem Link : https://codeforces.com/contest/1311/problem/A
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
		int a, b;
		cin >> a >> b;

		if(a == b)
			cout << 0 << endl;
		else if(a < b){
			if(a%2 == 0 and b&1){
				cout << 1 << endl;
			}
			else if(a%2 == 0 and b%2 == 0){
				cout << 2 << endl;
			}
			else if(a&1 and b%2==0){
				cout << 1 << endl;
			}
			else if(a&1 and b&1){
				cout << 2 << endl;
			}
		}
		else {
			if(a%2 == 0 and b&1){
				cout << 2 << endl;
			}
			else if(a%2 == 0 and b%2 == 0){
				cout << 1 << endl;
			}
			else if(a&1 and b%2==0){
				cout << 2 << endl;
			}
			else if(a&1 and b&1){
				cout << 1 << endl;
			}
		}

	}



}