// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//                             Author : Ankit Raj 
//         Problem Link : https://www.codechef.com/FEB20B/problems/THEATER
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <bits/stdc++.h>
#define int long long int
using namespace std;

map <int, int> mapped = {{12, 0}, {3, 1}, {6, 2}, {9, 3}}, priced = {{0, 100}, {1, 75}, {2, 50}, {3, 25}};
int table[4][4] = {0};

int solve(string s, string t, int movie)
{
    int ans = INT_MIN;
    if(movie == 4)
        return 0;
    for (int i = 0; i < 4; ++i)
    {
        if(s.find(to_string(i)) == string::npos)
        {
            for(int j = 0; j < 4; ++j)
            {
                int temp = 0;
                if(table[movie][i] == 0)
                    temp = -100 + solve(s + to_string(i), t, movie +1),ans = max(ans, temp);
                else if(t.find(to_string(j)) == string::npos)
                {
                    temp = priced[j]*table[movie][i] + solve(s + to_string(i), t + to_string(j), movie +1);
                    ans = max(ans, temp);
                }
                // ans = max(ans, temp);
            }
        }
    }
    // cout << ans << " ";
    return ans;
}

int32_t main()
{
    int t, sum = 0;
    cin >> t;
    while(t--)
    {
        int n, a;
        char m;
        cin >> n;
        memset(table, 0, sizeof(table));
        for(int i = 0; i < n; ++i)
            cin >> m >> a, table[m - 'A'][mapped[a]]++;
        int temp = solve("","",0);
        sum += temp;
        cout << temp << endl;
    }
    cout << sum << endl;
}

