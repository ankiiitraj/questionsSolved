// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//                               Author : Ankit Raj 
//                      Problem Name    :    XOR Game
//         		Problem Link : https://codechef.com/problems/XORGM
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <bits/stdc++.h>
#define int long long int
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
	
    int t; cin >> t; while(t--) {
    	int n, xorSum = 0;
    	cin >> n;
    	int a[n], c[n], flag = 0, temp;
        map <int, int> b;
    	for (int i = 0; i < n; ++i)
    		cin >> a[i], xorSum ^= a[i];

    	for (int i = 0; i < n; ++i)
    		cin >> temp, b[temp]++, xorSum ^= temp;
    	for(int i = 0; i < n; ++i){
            if(b[a[i]^xorSum] != 0){
                c[i] = a[i]^xorSum;
                b[a[i]^xorSum]--;
            } else {
                flag = 1;
            }

        }
        if(flag)
            cout << -1 << endl;
        else {
            for (int i = 0; i < n; ++i)
                cout << c[i] << " ";
        }



    }
    return 0;
}