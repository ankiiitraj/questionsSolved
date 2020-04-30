#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,k;
		cin>>n>>m>>k;
		ll a[n][k],b[100][n],s,g,arr[n],c[100],y=0;
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<k;j++)
				cin>>a[i][j];
		}
		srand((unsigned)time(0));
		for(ll i=0;i<100;i++)
		{
			for(ll j=0;j<n;j++)
				arr[j] = (rand()%(m))+1;
			for(ll j=0;j<n;j++)
				b[i][j]=arr[j];
			s=0;
			for(ll j=0;j<k;j++)
			{
				for(ll l=0;l<n;l++)
				{
					if(arr[l]==a[l][j])
						s++;
				}
			}
			c[i]=s/k;
		}
		g=c[0];
		for(ll i=1;i<100;i++)
		{
			if(c[i]>g)
			{
				g=c[i];
				y=i;
			}
		}
		for(ll i=0;i<n;i++)
			cout<<b[y][i]<<" ";
		cout<<"\n";
	}
	return 0;
}