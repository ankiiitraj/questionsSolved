// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//                             Author : Ankit Raj 
//                        Problem Code : Cow and Piles
//         Problem Link : https://codeforces.com/contest/1307/problem/A
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
        int n, d;
        cin >> n >> d;
        int a, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            if(i == 0)
                ans = a;
            else if(d > 0)
            {
                ans += min(d/(i), a);
                d -= min((d/(i))*i, a*i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}