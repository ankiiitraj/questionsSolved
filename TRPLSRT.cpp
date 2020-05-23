#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/* -------------------------------Solution Sarted--------------------------------------*/

struct wrapper{
	int i1, i2, i3;
};

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, k;
		cin >> n >> k;
		vi a(n +1), sorted;
		scnarr(a, n);
		vector<wrapper> ans;

		int cnt = 0;

		mii m;
		a[0] = 0;
		sorted.push_back(0);
		for(int i = 1; i <= n; ++i){
			m[a[i]] = i;
			sorted.push_back(i);
		}

		for(int i = 1; i <= n;){
			if(cnt >= k){
				break;
			}
			if(a[i] != i)
			{
				int i1, i2, i3;
				i1 = i;
				i3 = m[i1];
				i2 = a[i1];
				if(i2 == i1 or i2 == i3)
				{
					++i;
					continue;
				}
				// debug(i1, i2, i3);
				
				int temp = a[i1];
				a[i1] = a[i3];
				a[i3] = a[i2];
				a[i2] = temp;
				m[a[i1]] = i1, m[a[i2]] = i2, m[a[i3]] = i3;
				cnt++;
				ans.push_back({i1, i2, i3});
				
			}
			++i;
		}
		// debug(m, cnt);

		for(int i = 1; i <= n;)
		{
			if(cnt >= k)
			{
				break;
			}
			if(a[i] != i)
			{
				int i1, i2, i3;
				i1 = i;
				i3 = m[i1];
				i2 = a[i1];
				if(i2 == i1 or i2 == i3)
				{
					for(int j = i +1; j <= n; ++j)
					{
						if(a[j] != j and j != i3 and j != i1)
						{
							i2 = j;
							break;
						}
					}
				}
				// debug(i1, i2, i3);
				if(i2 == i1 or i2 == i3)
				{
					break;
				}
				int temp = a[i1];
				a[i1] = a[i3];
				a[i3] = a[i2];
				a[i2] = temp;
				m[a[i1]] = i1, m[a[i2]] = i2, m[a[i3]] = i3;
				cnt++;
				ans.push_back({i1, i2, i3});
				if(a[i] == sorted[i])
				{
					++i;
				}
			}
			else
			{
				++i;
			}
		}

		// debug(m);

		if(a == sorted)
		{
			cout << ans.size() << endl;
			for(auto itr: ans)
			{
				cout << itr.i1 << " " << itr.i2 << " " << itr.i3 << endl;
			}
		}
		else
		{
			puts("-1");
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	
