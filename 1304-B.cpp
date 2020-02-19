// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
                            // Author : Ankit Raj 
                    // Problem Name : Longest Palindrome
        // Problem Link : https://codeforces.com/contest/1304/problem/B
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
    // int t;
    // cin >> t;
    // while(t--)
{
    int n, m;
    cin >> n >> m;
    string s, ansL, ansR, ansM;
    map <string, int> mapSring;
    set <string> setString;
    for(int i = 0; i < n; ++i)
    {
        cin >> s;
        mapSring[s]++;
    }
    for(auto &itr:mapSring)
    {
        string s = itr.first;
        string sP = reverse(s);
        if(mapSring.find(sP) != mapSring.end() && setString.find(s) == setString.end())
        {
            setString.insert(s), setString.insert(sP);
            if(s == sP)
            {
                for(int i = 0; i < itr.S/2; ++i)
                {
                    ansR += s;
                    ansL = s + ansL;
                    mapSring[s] -= 2;
                }
            }
            else
            {
                while(mapSring[s] > 0 and mapSring[sP] > 0)
                {
                    ansR += s;
                    ansL = sP + ansL;
                    mapSring[s]--, mapSring[sP]--;
                }
            }
        }
    }
    for(auto &itr:mapSring)
    {
        if(itr.S > 0 and itr.F.length() > ansM.length() and itr.F == reverse(itr.F))
            ansM = itr.F;
    }
    cout << ansM.length()+ansL.length()+ansR.length() << " " << ansL << ansM << ansR << endl;}

}