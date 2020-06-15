#include <bits/stdc++.h>
#define int long long int
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
		int n;
		cin >> n;
		vi a(n);
		scnarr(a, n);

		vi ans;
		bool flag = a[0] - a[1] > 0 ? 0 : 1;
		ans.push_back(a[0]);
		for(int i = 0; i < n -1; ++i){
			if(flag){
				if(a[i +1] - a[i] < 0){
					flag = 0;
					ans.push_back(a[i]);
				}

			}else{
				if(a[i +1] - a[i] > 0){
					flag = 1;
					ans.push_back(a[i]);
				}
			}
		}
		ans.push_back(a[n -1]);
	
		cout << ans.size() << endl;

		for(auto itr: ans)
			cout << itr << " ";
		cout << endl;
	

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	