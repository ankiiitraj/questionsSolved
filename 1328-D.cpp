#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, cnt = 0;
		cin >> n;
		vi a(n), col(n, -1);
		scnarr(a, n);

		for(int i = 0; i < n; ++i){
			if(a[i] != a[i +1]){
				cnt++;
			}
		}
		if(a[n -1] == a[0])
			cnt--;
		else
			cnt++;

		if(cnt <= 0){
			cout << 1 << endl;
			for(int i = 0; i < n; ++i)
				cout << 1 << " ";
			cout << endl;
		}else if(cnt&1){
			int st, end;
			cout << 3 << endl;
			if(a[n -1] == a[0]){
				for(int i = 0; i < n -1; ++i){
					col[i] = 3;
					if(a[i] != a[i +1]){
						st = i +1;
						break;
					}
				}
				for(int i = n -1; i > 0; --i){
					col[i] = 3;
					if(a[i] != a[i -1]){
						end = i -1;
						break;
					}
				}
			}
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	