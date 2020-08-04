#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--){
		string s;
		cin >> s;
		int n = s.length();
		if(n == 1){
			cout << "-1\n";
			continue;
		}
		string y = s;
		for(int i = 0; i < n -1; ++i){
			while(y[i] > 'a' and y[i +1] < 'z'){
				y[i]--;
				y[i +1]++;
			}
		}
		if(y == s){
			sort(y.begin(), y.end());
			if((y[0] == 'a' and y[n -1] == 'a') or (y[0] == 'z' and y[n -1] == 'z')){
				cout << "-1\n";
				continue;
			}
			if(y[1] == 'z'){
				y[1]--;
				y[0]++;
			}else if(y[0] == 'a'){
				for(int i = 1; i < n; ++i){
					if(y[i] != 'a'){
						if(y[i] == 'z'){
							y[i]--;
							y[i -1]++;
						}else if(i == n -1){
							y[i]--;
							y[i -1]++;
						}else if(y[i +1] == 'z'){
							y[i +1]--;
							y[i]++;
						}else{
							y[i]--;
							y[i +1]++;
						}

						break;
					}
				}
			}
		}
		int hash = 0;
		for(int i = 0; i < n; ++i){
			hash += y[i] - 'a';
		}		
		
		cout << hash << " " << y << endl;
	
	}

}