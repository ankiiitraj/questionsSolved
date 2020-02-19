// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//                             Author : Ankit Raj 
//         Problem Link : https://www.codechef.com/FEB20B/problems/SNUG_FIT
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n, x, ans = 0;
        cin >> n;
        vector <int> a, b;
        for(int i = 0; i < n; ++i)
            cin >> x, a.push_back(x);
        for(int i = 0; i < n; ++i)
            cin >> x, b.push_back(x);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = a.size() -1; i >= 0; --i)
        {
            ans += min(a[i], b[i]);
        }
        cout << ans << endl;
    }
}

