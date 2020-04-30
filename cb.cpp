#include<bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	int a[n], dp1[n] = {0}, dp2[n] = {0}, b[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		b[n - i -1] = a[i];
	}
	dp1[0] = 1, dp2[0] = 1;

	for(int i = 1; i < n; ++i){
		dp1[i] = dp2[i] = 1;
		for(int j = 0; j < i; ++j){
			if(a[i] > a[j] and dp1[i] < dp1[j] +1){
				dp1[i] = dp1[j] +1;
			}
			if(b[i] > b[j] and dp2[i] < dp2[j] +1){
				dp2[i] = dp2[j] +1;
			}
		}
	}
	int ans = -1, res = 0, resMax = -1;
	for(int i = 0; i < n; ++i){
		ans = max(ans, dp1[i] + dp2[i] -1);
	}
	for(int i = 0; i < n; ++i){
		res = 0, ans = -1;
		if(dp1[i] + dp2[i] -1 == ans){
			res += a[i];
			int prev = a[i];
			for(int j = i -1, cnt = 1; j >= 0; --j){
				if(a[j] < prev){
					cnt++;
					prev = a[j];
					res += a[j];
				}
				if(cnt == dp1[i])
					break;
			}
			prev = a[i];
			for(int j = i +1, cnt = 0; j < n; ++j){
				if(a[j] < prev){
					cnt++;
					prev = a[j];
					res += a[j];
				}
				if(cnt == dp2[i]){
					break;
				}
			}
		}
		resMax = max(res, resMax);
	}
	cout << res << endl;
	return 0;
}