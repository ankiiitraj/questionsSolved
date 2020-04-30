// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//                             Author : Ankit Raj 
//         Problem Link : https://www.codechef.com/FEB20B/problems/NOCHANGE
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
        bool flag = 0;
        map <int, int> ans;
        int n, p;
        cin >> n >> p;
        int temp = p;
        vector <int> d(n);
        for(int i = 0; i < n; ++i)
        {
            ans[i] = 0;
            cin >> d[i];
            if(p%d[i] != 0)
                flag = 1;
        }
        if(!flag)
        {
            if(n == 1)
                cout << "NO";
            else
            {
                int index = n -1;
                for(; index >= 0; --index)
                {
                    if(p%d[index] != 0)
                    {
                        flag = 1;
                        ans[index] = p/d[index] +1;
                        break;
                    }
                    ans[index] = p/d[index] -1;
                    p -= (d[index]*(p/d[index] -1));
                }
                if(!flag)
                    cout << "NO";
                else
                {
                    cout << "YES ";
                    for(int i = 0; i < n; ++i)
                    {
                        cout << ans[i] << " ";
                    }
                }
            }
        }
        else
        {
            cout << "YES ";
            int index = n -1;
            for(; index >= 0; --index)
                if(p%d[index] != 0)
                    break;
            for(int i = 0; i < n; ++i)
            {
                if(i != index)
                    cout << "0 ";
                else
                    cout << p/d[index] +1 << " ";
            }
        }

        cout << endl;

    }
}

