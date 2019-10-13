/*
  Author - KISHAN TIWARI
  Dream bigger. Do bigger.
  Wake up with determination. Go to bed with satisfaction.
*/
//Sometimes later becomes never. Do it now.
#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define f(i,a,b)     for(ll i=a;i<b;i++)
#define mod          1000000007
#define fi           first
#define se           second
#define pa           pair <ll,ll>
#define mp           make_pair
#define pb           push_back
#define ve           vector<ll>
#define vep          vector< pa >
#define all(a)       a.begin(), a.end()
#define sz(x)        (ll)x.size()
#define c(t)         cout<<t<<"\n"
using namespace std;
//Time complexity of this dijkstra is O(NlogN+E)
ll in=100000000000000000;
vector<vector<pa> > adj(100001);
vector<ll> d(100001,in);
vector <ll>p(100001,-1);
void Dj_Algo(ll s,ll n)
{  //vector<bool> used(n+1,0);

    d[s]=0;

   //used[s]=1;
   set<pa> q;
   q.insert({0,s});
    while(!q.empty())
    {
        ll v=q.begin()->se;
        /*f(j,1,n+1)
        {
         if(!used[j]&&(v==-1||d[v]>=d[j]))
                v=j;
        }*/
        if(d[v]==in)
            break;
        q.erase(q.begin());
        //used[v]=1;
        for(ll j=0;j<adj[v].size();j++)
        {  ll to=adj[v][j].fi;
           ll w=adj[v][j].se;
            if(d[to]>d[v]+w)
                {q.erase({d[to],to});
                 d[to]=d[v]+w;
                 p[to]=v;
                 q.insert({d[to],to});
                }
        }
    }
}
void solve()
{  ll n,m,f;
cin>>n>>m>>f;
ll a[n];
f(i,0,n)
cin>>a[i];
f(i,0,m)
{
    ll u,v,x;
    cin>>u>>v>>x;
    adj[u].pb({v,x});
    adj[v].pb({u,x});
}
ll k;
cin>>k;
Dj_Algo(1,n);
vector<pa> g;
f(i,1,n+1)
    g.pb({d[i],i});
sort(all(g));
ll j=0,x=0;
while(1)
{   
    if(x>=k)
     break;
    if(j>=n)
    {    cout<<"-1 ";
         x++;
    }
    else if(a[g[j].se-1]>0)
    {
        cout<<g[j].fi+f<<" ";
        a[g[j].se-1]--;
        x++;
    }
    else
    {   
        j++;
    }
}
}
int main()
{
    ios::sync_with_stdio(true);
   //freopen ("input.txt","r",stdin);
   //freopen ("output.txt","w",stdout);
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
