#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
const int mod = 1000000007;
int fac[500001];
int mod_inverse[500001];
vector<int>adj[500001];
void add(int &x, int y)
{       x+=y;
        if(x>=mod)
        x-=mod;
        if(x<0)
        x+=mod;
}
int mul(int x, int y)
    {
        return ((ll)x * y)%mod;
    }
int power(int a ,int p)
{
    int ret = 1;
    while(p)
    {
        if(p&1)
            ret=mul(ret,a);
        a=mul(a,a);
        p/=2;
    }
    return ret;
}
int inv(int x)
{
    return power(x, mod-2);
}
void factorial()
{
    fac[0] = 1; mod_inverse[0]=1;

    for (int i = 1; i <=500000; i++)
            {
                fac[i] = mul(fac[i-1],i);
                mod_inverse[i]=mul(inv(i),mod_inverse[i-1]);
            }
}
int ncr(int n, int r)
{
    if(r==0)
        return 1;
    else if(r==n)
        return 1;
  return mul(fac[n], mul(mod_inverse[r], mod_inverse[n-r]));
}
int main()
{
    factorial();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int ,int >freq;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            freq[x]++;
        }
        for(auto i=freq.begin();i!=freq.end();i++)
        {
            if (adj[i->second].empty())
            {
                adj[i->second].pb(1);
                for (int r = 1; r <= i->second; r++)
                {
                    int x = adj[i->second].back();
                    add(x, ncr(i->second,r));
                    adj[i->second].pb(x);
                }
            }
        }
        vector<int>b;
        int maxx=0;
       for(auto i=freq.begin();i!=freq.end();i++)
       {
           b.pb(i->first);
           maxx=max(maxx, i->second);
       }
       int cnt=maxx;
       vector<pair<int,int>>arr;
       while(cnt!=0)
       {
           for(auto i=0;i<b.size();i++)
           {
               if(freq[b[i]]>=cnt)
                arr.pb({b[i],cnt});
           }
           cnt--;
        }

        vector<int>ans(n+1);
        int i=0;
        int v=1;
        int current, total,value;
        x=arr[i].first;
        current=arr[i].second;
        total=freq[x];
        value=ncr(total, current);
        v=mul(v,value);
        for(auto j=freq.begin();j!=freq.end();j++)
        {
                if(j->first!=x)
                v=mul(v,adj[j->second].back());
        }
        add(ans[x],v);
        v=mul(v, inv(value));
        v = mul(v, adj[total][current-1]);
        for (i=1;i<arr.size();i++)
        {
            x= arr[i].first;
            current = arr[i].second;
            total= freq[x];

            v = mul(v, inv(adj[total][current]));
            value = ncr(total,current);
            v = mul(v, value);

            add(ans[x],v);

            v = mul(v, inv(value));
            v = mul(v, adj[total][current-1]);
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;


    }
    return 0;
}