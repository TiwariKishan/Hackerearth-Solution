#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
#define fi first
#define se second
#define pa pair
#define mp make_pair
#define pb push_back
#define ve vector<ll>
#define vep vector< pa<ll ,ll> >
#define c(t) cout<<t<<"\n"
using namespace std;
ve parent,size;
multiset<ll> q;
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
    q.insert(1);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        q.erase(q.find(size[a]));
        q.erase(q.find(size[b]));
        size[a] += size[b];
        q.insert(size[a]);
    }
}
void solve()
{  ll n,m;
cin>>n>>m;
parent.assign(n+1,0);
size.assign(n+1,0);
f(i,1,n+1)
make_set(i);
f(i,0,m)
{
    ll x,y;
    cin>>x>>y;
    union_sets(x,y);
    ll ma=*q.begin();
    ll mi=*(--q.end());
    ll xs=abs(ma-mi);
    c(xs);
}
}
int main()
{
    ios::sync_with_stdio(true);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)
    {

        solve();
    }
return 0;
}
