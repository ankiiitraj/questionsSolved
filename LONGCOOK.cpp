// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//                             Author : Ankit Raj 
//         Problem Link : https://www.codechef.com/FEB20B/problems/LONGCOOK/
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * #include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define F first
#define S second
using namespace std;

int dayofweek(int d, int m, int y) 
{ 
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                    5, 1, 4, 6, 2, 4 }; 
    y -= m < 3; 
    return ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7; 
} 

int32_t main() 
{ 
    #ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    #endif
    vector<int> dp[13];
    for(int i = 0; i <= 12; ++i)
        for(int j = 0; j <= 400; ++j)
            dp[i].pb(0);
    for(int i = 1; i <= 400; ++i)
    {
        for(int j = 1; j < 13; ++j)
        {
            if(j == 1)
            {
                dp[j][i] = dp[12][i -1];
            }
            else if(j == 2)
            {
                if(((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
                {
                    if(dayofweek(1, 2, i) == 6)
                        dp[j][i] = dp[j -1][i] +1;
                    else
                        dp[j][i] = dp[j -1][i];
                }
                else if(dayofweek(1, 2, i) == 0 or dayofweek(1, 2, i) == 6)
                    dp[j][i] = dp[j -1][i] +1;
                else
                    dp[j][i] = dp[j -1][i];
            }
            else
                dp[j][i] = dp[j -1][i];
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        int m1, y1, m2, y2, ans = 0, startToy1, startToy2, start1rem, start2rem;
        cin >> m1 >> y1 >> m2 >> y2;
        startToy1 = (y1/400)*101;
        startToy2 = (y2/400)*101;
        start1rem = y1%400;
        start2rem = y2%400;
        
        startToy1 += (m1 == 1 ? dp[m1][start1rem]: dp[m1 -1][start1rem]);
        startToy2 += dp[m2][start2rem];
        
        cout << startToy2 - startToy1 << endl;
    }
}