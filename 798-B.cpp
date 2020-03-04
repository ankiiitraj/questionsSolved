#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
// const int N = 100005;

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while (t--)
	{
		int n, curAns = 0, ans = LONG_MAX, flag = 0;
		cin >> n;
		string s[n];
		for(int i = 0; i < n; ++i)
			cin >> s[i];
		int sLen = s[0].len();
		string temp, cur = s[0];
		for(int i = 0; i < sLen; ++i){
			if(i != 0){
				s[0] = s[0].substr(1, s[0].length()) + s[0][0];
			}
			curAns = 0;
			for(int j = 1; j < n; ++j){
				int k = 0;
				temp = s[j];
				for(; k < sLen; ++k){
					if(temp != s[0]){
						temp = temp.substr(1, temp.len()) + temp[0];
					}else{
						break;
					}
				}
				if(k == sLen){
					flag = 1;
					break;
				}else{
					curAns += k;
				}
			}
			if(flag)
				break;
			ans = min(ans, curAns + i);
		}
		if(flag)
			cout << "-1\n";
		else{
			cout << ans << endl;
		}

	}
}