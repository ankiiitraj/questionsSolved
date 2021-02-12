#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
const int N = 100005;

// struct combination{
// 	int r, c, p;
// };


int32_t main()
{
faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		int h, w, q, r, c, p;
		cin >> h >> w >> q;
		int a[h][w], falg = 0;
		// combination comb[q];
		for(int i = 0; i < h; ++i){
			for (int j = 0; j < w; ++j)
			{
				cin >> a[i][j];
				if(a[i][j] != a[0][0])
					falg = 1;
			}
		}
		for(int i = 0; i < q; ++i){
			cin >> r >> c >> p;
			--r, --c;
			if(falg == 0){
				if(p > a[r][c])
					cout << h*w << endl;
				else
					cout << 0 << endl;
			}else if(h == 1){
				int ans = 1;
				if(a[r][c] >= p){
					cout << 0 << endl;
					continue;
				}
				for(int i = c +1; i < w; ++i){
					if(a[r][i] < p){
						ans++;
					}else{
						break;
					}
				}
				for(int i = c -1; i >= 0; --i){
					if(a[r][i] < p){
						ans++;
					}else{
						break;
					}
				}
				cout << ans << endl;
			}
				
			
 		}

	}
}