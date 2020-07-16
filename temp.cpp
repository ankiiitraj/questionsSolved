#include <bits/stdc++.h>
#define ll long long
using namespace std;

stack<ll> makeItEmpty(stack<ll> in){
    stack<ll> temp;
    in.swap(temp);
    return in;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    ll h[n], s[n], rSum[n], lSum[n], left[n], right[n];
    for(ll i=0;i<n;i++)
        cin>>h[i];
    for(ll j=0;j<n;j++)
        cin>>s[j];
    stack<ll> se1, se2;
    for(ll i=n-1;i>=0;i--){
        rSum[i]=s[i];
        while(!se1.empty()&&h[se1.top()]<=h[i])
            se1.pop();
        if(!se1.empty())
            rSum[i]+=rSum[se1.top()];
        se1.push(i);
    }
    for(int i=0;i<n;i++){
        lSum[i]=s[i];
        while(!se2.empty()&&h[se2.top()]<=h[i])
            se2.pop();

        if(!se2.empty())
            lSum[i]+=lSum[se2.top()];

        se2.push(i);
    }
    se1= makeItEmpty(se1);
    se2= makeItEmpty(se2);
    for(ll i=n-1;i>=0;i--){
        while(!se1.empty()&&h[se1.top()]<h[i])
            se1.pop();
        right[i]= (se1.empty()) ? n: se1.top();
        se1.push(i);
    }
    for(int i=0;i<n;i++){
        while(!se2.empty()&&h[se2.top()]<h[i])
            se2.pop();
        left[i]= (se2.empty()) ? -1: se2.top();
        se2.push(i);
    }

     while(q--){
        ll t, a, b;
        cin>>t>>a>>b;
        if(t==1){
            s[a-1]=b;
            se1= makeItEmpty(se1);
            se2= makeItEmpty(se2);
            for(ll i=n-1;i>=0;i--){
                rSum[i]=s[i];
                while(!se1.empty()&&h[se1.top()]<=h[i])
                    se1.pop();
                if(!se1.empty())
                    rSum[i]+=rSum[se1.top()];
                se1.push(i);
            }
            for(int i=0;i<n;i++){
                lSum[i]=s[i];
                while(!se2.empty()&&h[se2.top()]<=h[i])
                    se2.pop();

                if(!se2.empty())
                    lSum[i]+=lSum[se2.top()];

                
            }
        }
        else{
            a--;
            b--;
            if(a==b){
                cout<<s[a]<<"\n";
                continue;
            }
            
            if(abs(b-a)==1){
                cout<<s[a]+s[b]<<"\n";
                continue;
            }
            if(a > b){
                cout<<rSum[b]-rSum[a]+s[a]<<"\n";

            }else if(a<b){
              
                cout<<lSum[b]-lSum[a]+s[a]<<"\n";
            }
        }
     }


    return 0;
}