#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 1000001; // 1e6 +1

/* -------------------------------Solution Sarted--------------------------------------*/

/*Code for prefix sum using binaryIndexedTree*/
vi BIT(200005); //Enter the size
void update(int ind, int val, int n){
	BIT.resize(n +2);
	for(; ind <= n; ind += (ind&-ind))
		BIT[ind] += val;
}
int query(int ind){
	int res = 0;
	for(; ind > 0; ind -= (ind&-ind))
		res += BIT[ind];
	return res;
}

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		int n;
		cin >> n;
		vi a(n +1), b(n +1)
		map<int, pii> m;
		scnarr(a, n);
		scnarr(b, n);
		for (int i = 1; i <= n; ++i){
			m[a[i] - b[i]].first++;
		}
		debug(m);
		int i = 1, cur, req, ans = 0;
		int temp[m.size() +1], prefix; 
		for(auto &itr:m){
			itr.second.second = i;
			update(i, itr.second.first, n);
			temp[i] = (itr.first);
			++i;
		}
		
		for(int i = 1; i <= n; ++i){
			cur = a[i] - b[i];
			req = -cur +1;
			int* itr = lower_bound(temp +1, temp + m.size() +1, req);
			int ind = itr - (temp);
			if(ind == 1){
				update(m[cur].second, -1, n);
				ans += query(n);
			}
			else if(ind <= n -1){
				update(m[cur].second, -1, n);

				ans += query(n) - query(ind -1); 
			}
		}
		cout << ans << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
