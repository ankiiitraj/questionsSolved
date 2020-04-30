#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scn(a) scanf("%lld", &a)
#define scnarr(a, n) for (int i = 0; i < n; ++i) scanf("%lld", &a[i])
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000001; // 1e6 +1

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
		int n, k, a, flag = 0;
		cin >> n >> k;
		string s[n], temp;
		for(int i = 0; i < 64; ++i)
			temp += '0';
		set <int> visited;

		for (int i = 0; i < n; ++i){
			cin >> a;
			s[i] = temp;
			int j = 0;
			while(a >= k){
				s[i][j] = a%k == 0 ? '0' : a%k == 1 ? '1' : '2';
				a /= k;
				++j;
			}
			s[i][j] = a%k == 0 ? '0' : a%k == 1 ? '1' : '2';
		}
		
		for(auto itr:s){
			for(int i = 0; i < itr.len(); ++i){
				if(itr[i] > '1'){
					flag = 1;
				}else if(itr[i] == '1' and visited.find(i) == visited.end()){
					visited.insert(i);
				}else if(itr[i] != '0'){
					flag = 1;
				}
			}
		}
		flag ? cout << "NO\n" : cout << "YES\n";
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :