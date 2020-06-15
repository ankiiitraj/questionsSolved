#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mid(L,R) ((L+R)/2)

struct NodeVar{
    int cnt , L , R;
    NodeVar()
    {
        cnt=0;
        L = R = -1;
    }
    NodeVar(int x,int y,int z)
    {
        L = x;
        R = y;
        cnt = z;
    }
}tree[8160001];


int scanin()
{
    register int n=0;
    char ch=getchar_unlocked();
    for(;(ch<48||ch>57);ch=getchar_unlocked())
        ;
    for(;(ch>47&&ch<58);ch=getchar_unlocked())
        n=(n<<3)+(n<<1)+ch-48;
    return n;
}
int G[1000001];
int A[200001],root[200001],RM[200001],B[200001],V[200001];
int gc = 0 , N;

int build(int L , int R)
{
    ++gc;
    if(L==R)
        return gc;
    int x = gc;
    tree[x] = NodeVar(build(L,mid(L,R)),build(mid(L,R)+1,R),0);
    return x;
}


int update(int L , int R , int root , int idx , int val)
{
    if(L>idx || R<idx)
        return root;
    ++gc;
    if(L==idx&&R==idx)
    {
        tree[gc] = NodeVar(-1,-1,tree[root].cnt+val);
        return gc;
    }
    int x = gc;
    tree[x]=NodeVar(update(L,mid(L,R),tree[root].L,idx,val),update(mid(L,R)+1,R,tree[root].R,idx,val),tree[root].cnt+val);
    return x;
}

int query(int L , int R , int root , int qe , int qr)
{
    if(qr<L || qe>R)return 0;
    if(qe<=L && R<=qr)
        return tree[root].cnt;
    return query(L,mid(L,R),tree[root].L,qe,qr)+
            query(mid(L,R)+1,R,tree[root].R,qe,qr);
}

vector <int> adj[200005], a;
vector<bool> visited;
int n;

set <int> s;
void dfs(int x, int cur, int d)
{
    visited[x] = 1;
    s.insert(A[x]);
    if(cur == d)
    {
        return;
    }

    for(auto itr: adj[x])
    {
        if(!visited[itr])
        {
            dfs(itr, cur +1, d);
        }
    }
}

int query(int x, int d)
{
    visited.resize(n +1);
    for(int i = 0; i <= n; ++i)
        visited[i] = false;
    s.clear();
    dfs(x, 0, d);   
    int ans = s.size();
    return ans;
}


int32_t main()
{
    int test; test = scanin();while(test--){
        int  M , i , x , y , z, ans = 0;
        gc = 0;

        N  = scanin();
        n = N;

        memset(G,-1,sizeof(G));
        if(N <= 1000){
            int temp;
            for(int i = 0; i <= n; ++i)
                adj[i].clear();
            
            for(int i = 2; i <= n; ++i)
            {
                temp = scanin();
                adj[temp].push_back(i);
            }
        }else{
            for(i=1;i<N;++i){A[i]=scanin();}
        }
        for(i=1;i<=N;++i){A[i]=scanin();}
        M  = scanin();
        if(N <= 1000 and M <= 1000)
        {

            while(M--)
            {
                int x, d;
                x = scanin();
                d = scanin();
                x = x^ans;
                d = d^ans;
                ans = query(x, d);
                cout << ans << endl;
            }
            continue;
        }
        root[0] = build(1,N);
        for(i=1;i<=N;++i)
        {
            int p = root[i-1];
            if(G[A[i]]!=-1)
                p = update(1,N,p,G[A[i]],-1);
            root[i] = update(1,N,p,i,1);
            G[A[i]]=i;
        }

        for(;M;--M)
        {
            x = scanin();
            y = scanin();
            x = ans^x;
            y = ans^y;
            int dist = x + y;
            if(x + y > N)
                dist = N;
            ans = query(1,N,root[dist],x,dist);
            printf("%lld\n", ans);
        }

    }

    return 0;
}