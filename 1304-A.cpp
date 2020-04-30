// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
                            // Author : Ankit Raj 
                    // Problem Name : Two Rabbits
        // Problem Link : https://codeforces.com/contest/1304/problem/A
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define F first
#define S second
using namespace std;

string reverse(string s)
{
    string temp;
    for(auto itr:s)
    {
        temp = itr + temp;
    }
    return temp;
}

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

        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int ans = (y - x)/(a + b);
        long double ansD = ((long double)(y - x))/((long double)(a + b));
        if(ans == ansD)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    
}