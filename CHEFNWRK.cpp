#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--){
		int n, k, res = 0, cur = 0, a;
		cin >> n >> k;
		for(int i = 0; i < n; ++i){
			cin >> a;
			cur += a;
			if(a > k)
				res = -10000000;
			if(cur > k){
				res++;
				cur = a;
			}
		}
		cout << (res < 0 ? -1 : res +1) << endl;
	}
}