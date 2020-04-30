#include <bits/stdc++.h>
#define int long long int
// #define all(a) (a.begin(), a.end())
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
	// int t; cin >> t; while(t--)
	{
		string s;
		cin >> s;
		int n = s.len(), cntC = 0, cntO = 0;
		vector <int> ans, ans2;
		int i = 0, j = n;
		bool zero = true;
	
		for(; i < n; ++i){
			if(s[i] == '('){
				ans.push_back(i);
				cntO++;
				zero = true;
				break;
			}
		}
		while(j > i){
			if(zero == true){
				while(j > i){
					--j;
					if(s[j] == ')'){
						zero = false;
						ans.push_back(j);
						cntC++;
						break;
					}
				}
			}else{
				while(j > i){
					++i;
					if(s[i] == '('){
						zero = true;
						ans.push_back(i);
						cntO++;
						break;
					}
				}
			}
		}
		int ansSize = ans.size();
		if(cntO != cntC){
			ansSize--;
		}
		for(int i = 0; i < ansSize; ++i)
			ans2.push_back(ans[i]);
		if(ansSize == 0){
			cout << 0 << endl;
			return 0;
		}
		sort(ans2.begin(), ans2.end());
		cout << 1 << endl << ansSize << endl;
		for(int i = 0; i < ansSize; ++i)
			cout << ans2[i] +1 << " ";
		cout << endl;
	}
	return 0;
}
