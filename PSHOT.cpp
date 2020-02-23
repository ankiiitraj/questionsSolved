// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj
//                      Problem Name    :    PSHOT
//         		Problem Link : https://www.codechef.com/COOK115B/problems/PSHOT
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
		int n, flag = 0;
		string s;
		cin >> n >> s;
		int sA = 0, sB = 0, cnt = 1, cntA = n, cntB = n;
		for (auto itr : s) {
			if (cnt & 1 and itr == '1') {
				sA++;
			} else if (!(cnt & 1) and itr == '1') {
				sB++;
			} else if (cnt & 1) {
				cntA--;
			} else if (!(cnt & 1)) {
				cntB--;
			}
			if (sB + cntB < sA) {
				cout << cnt << endl;
				break;
			} else if (sA + cntA < sB) {
				cout << cnt << endl;
				break;
			} else if(cnt == 2*n){
				cout << 2*n << endl;
			}
			cnt++;
		}
	}


	return 0;
}