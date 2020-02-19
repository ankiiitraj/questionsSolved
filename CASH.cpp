* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
                            Author : Ankit Raj 
        Problem Link : https://www.codechef.com/FEB20B/problems/CASH
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <bits/stdc++.h>
#define ll long long int
#define lld long double
#define scnstr(s) scanf("%s", s)
#define rep(i,j,k) for(ll i = j; i < k; ++i)
#define pb push_back
#define mp make_pair
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
 
int main() {
    faster;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, k, a, sum = 0;
        cin >> n >> k;
        for(ll i = 0; i < n; ++i)
            cin >> a, sum += a;
       cout << sum % k << endl;
    }
    return 0;
}
