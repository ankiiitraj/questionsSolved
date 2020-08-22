#include <bits/stdc++.h>
#define int long long
using namespace std;

int count_digs(int n){
	int cnt = 0;
	while(n){
		n /= 10;
		cnt++;
	}
	return cnt;
}

int power(int x, int y){
	int ans = 1;
	while(y > 0){
		if(y&1){
			ans = (ans * x);
			--y;
		}else{
			x = (x * x);
			y /= 2;
		}
	}
	return ans;
}

vector<int> to_vector(int n){
	vector<int> res;
	while(n){
		res.push_back(n%10);
		n /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int find_count(int n, int k){
	if(n == 0){
		return 0;
	}
	int dig_count = count_digs(n);
	if(dig_count == 1){
		return (int)(n/k);
	}
	vector<int> dig_arr = to_vector(n);

	int res = 0;

	for(int i = 1; i < dig_count; ++i){
		res += power((int)(9/k) +1, i -1)*(9/k);
	}
	if(dig_arr[0]%k == 0){
		res += power((int)(9/k) +1, dig_count -1)*((dig_arr[0] -1)/k);
		for(int i = 1; i < dig_count; ++i){
			if(dig_arr[i] != 0){
				if(i == dig_count -1){
					res += (int)(dig_arr[i]/k) +1;
					return res;
				}else{
					res += power((int)(9/k) +1, dig_count - i -1)*((int)((dig_arr[i] -1)/k) +1);
				}
				if(dig_arr[i]%k != 0){
					return res;
				}
			}else if(i == dig_count -1 and dig_arr[i] == 0){
				return res +1;
			}
		}
	}else{
		res += power((int)(9/k) +1, dig_count -1)*((int)(dig_arr[0]/k));
	}
	return res;
}


signed main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int l, r, k;
		cin >> l >> r >> k;

		int res_l = find_count(l -1, k);
		int res_r = find_count(r, k);

		// cout << res_r << " "; 
		// cout << res_l << endl;
		cout << res_r - res_l << endl;
	}
}