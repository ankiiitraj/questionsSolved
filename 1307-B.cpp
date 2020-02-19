// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//                             Author : Ankit Raj 
//                      Problem Name  : Cow 
//         Problem Link : https://codeforces.com/contest/1307/problem/B
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;


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
        int n, x;
        cin >> n >> x;
        int a[n], ans = -1, _max = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if(a[i] == x)
                ans = 1;
            if(_max < a[i])
                _max = a[i];
        }
        if(ans > 0){
            cout << ans << endl;
        } else{
            if(_max > x)
                cout << 2 << endl;
            else if(x%_max == 0){
                cout << x/_max << endl;
            } else{
                cout << (x/_max +1) << endl;        
            }
        }


    }
    return 0;
}