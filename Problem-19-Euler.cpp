// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj 
//                      Problem Name    :    Dates
//              Problem Link : https://projecteuler.net/problem=19
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * #include <bits/stdc++.h>
#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define F first
#define S second
using namespace std;

int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4
                     };
    y -= m < 3;
    return ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

bool ifLeap(int y){
    if((y%4 == 0 and y%100 != 0) or y%400 == 0)
        return true;
    return false;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int ans = 0;
    for(int i = 1901; i <= 2000; ++i){
        for(int j = 1; j <= 12; j++){
            if(dayofweek(1, j, i) == 0)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}