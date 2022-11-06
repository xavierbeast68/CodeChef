/**
 * @author xavierbeast68
 * Problem Name- Tri XOR ( Codechef Starters 60)
 * Problem Link- https://www.codechef.com/submit/TRIXOR
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

//* Setter's Solution
/*
//Utkarsh.25dec
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=500023;
bool vis[N];
vector <int> adj[N];
long long readInt(long long l,long long r,char endd){
    long long x=0;
    int cnt=0;
    int fi=-1;
    bool is_neg=false;
    while(true){
        char g=getchar();
        if(g=='-'){
            assert(fi==-1);
            is_neg=true;
            continue;
        }
        if('0'<=g && g<='9'){
            x*=10;
            x+=g-'0';
            if(cnt==0){
                fi=g-'0';
            }
            cnt++;
            assert(fi!=0 || cnt==1);
            assert(fi!=0 || is_neg==false);

            assert(!(cnt>19 || ( cnt==19 && fi>1) ));
        } else if(g==endd){
            if(is_neg){
                x= -x;
            }

            if(!(l <= x && x <= r))
            {
                cerr << l << ' ' << r << ' ' << x << '\n';
                assert(1 == 0);
            }

            return x;
        } else {
            assert(false);
        }
    }
}
string readString(int l,int r,char endd){
    string ret="";
    int cnt=0;
    while(true){
        char g=getchar();
        assert(g!=-1);
        if(g==endd){
            break;
        }
        cnt++;
        ret+=g;
    }
    assert(l<=cnt && cnt<=r);
    return ret;
}
long long readIntSp(long long l,long long r){
    return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
    return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
    return readString(l,r,'\n');
}
string readStringSp(int l,int r){
    return readString(l,r,' ');
}
void solve()
{
    int n=readInt(6,1000,'\n');
    ll A[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        if(i==n)
            A[i]=readInt(0,1000000000,'\n');
        else
            A[i]=readInt(0,1000000000,' ');
    }
    vector <tuple<ll,ll,ll>> opers;
    for(int bit=0;bit<=30;bit++)
    {
        set <int> indices;
        for(int i=1;i<=n;i++)
        {
            if((A[i]&(1<<bit))!=0)
                indices.insert(i);
        }
        while(indices.size()>=3)
        {
            int p=(*indices.begin());
            indices.erase(p);
            int q=(*indices.begin());
            indices.erase(q);
            int r=(*indices.begin());
            indices.erase(r);
            ll P=A[p], Q=A[q], R=A[r];
            opers.pb(make_tuple(P, Q, R));
            A[p]=(P^Q);
            A[q]=(Q^R);
            A[r]=(R^P);
        }
        if(indices.size()==1)
        {
            int p=(*indices.begin());
            vector <int> fun;
            fun.pb(p);
            for(int i=1;i<=n;i++)
            {
                if(fun.size()==3)
                    break;
                if(i==p)
                    continue;
                fun.pb(i);
            }
            for(auto it:fun)
                indices.insert(it);
            p=fun[0];
            int q=fun[1];
            int r=fun[2];
            ll P=A[p], Q=A[q], R=A[r];
            opers.pb(make_tuple(P, Q, R));
            A[p]=(P^Q);
            A[q]=(Q^R);
            A[r]=(R^P);
            indices.erase(q);
        }
        if(indices.size()==2)
        {
            int p=(*indices.begin());
            indices.erase(p);
            int q=(*indices.begin());
            vector <int> fun;
            fun.pb(p);
            for(int i=1;i<=n;i++)
            {
                if(fun.size()==3)
                    break;
                if(i==p)
                    continue;
                if(i==q)
                    continue;
                fun.pb(i);
            }
            p=fun[0];
            q=fun[1];
            int r=fun[2];
            ll P=A[p], Q=A[q], R=A[r];
            opers.pb(make_tuple(P, Q, R));
            A[p]=(P^Q);
            A[q]=(Q^R);
            A[r]=(R^P);
            indices.insert(p);
            indices.insert(r);
        }
        if(indices.size()==3)
        {
            int p=(*indices.begin());
            indices.erase(p);
            int q=(*indices.begin());
            indices.erase(q);
            int r=(*indices.begin());
            indices.erase(r);
            ll P=A[p], Q=A[q], R=A[r];
            opers.pb(make_tuple(P, Q, R));
            A[p]=(P^Q);
            A[q]=(Q^R);
            A[r]=(R^P);
        }
    }
    cout<<opers.size()<<'\n';
    for(auto it:opers)
        cout<<get<0>(it)<<' '<<get<1>(it)<<' '<<get<2>(it)<<'\n';
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int T=readInt(1,10,'\n');
    while(T--)
        solve();
    assert(getchar()==-1);
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
*/

//* Tester's Solution
/*
#include <bits/stdc++.h>
using namespace std;

void modify(int a, int b, int c, vector<int> &v) {
    int v1 = (v[a]^v[b]), v2 = (v[b]^v[c]), v3 = (v[c]^v[a]);
    v[a] = v1;
    v[b] = v2;
    v[c] = v3;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<tuple<int, int, int>> ops;
        for(int i = 0; i < 31; i++) {
            vector<int> set; int cnt = 0;
            for(int j = 1; j <= n; j++) {
                cnt += ((a[j]&(1LL<<i)) > 0);
                if(((a[j]&(1LL<<i)) > 0))
                    set.push_back(j);
            }
           for(int j = 0; j < cnt - cnt%3; j+=3) {
               ops.push_back({a[set[j]], a[set[j + 1]], a[set[j + 2]]});
               modify(set[j], set[j + 1], set[j + 2], a);
           }
           if(cnt%3 == 1) {
               int z1 = 0, z2 = 0;
               for(int j = 1; j <= 6; j++)
                if((a[j]&(1LL<<i)) == 0)
                    z1 = z2, z2 = j;
               ops.push_back({a[set[cnt - 1]], a[z1], a[z2]});
               modify(set[cnt - 1], z1, z2, a);
               for(int j = 1; j <= 6; j++)
                if((a[j]&(1LL<<i)) == 0)
                    z1 = z2, z2 = j;
               ops.push_back({a[set[cnt - 1]], a[z1], a[z2]});
               modify(set[cnt - 1], z1, z2, a);
           } else if(cnt%3 == 2) {
               int z1 = 0, z2 = 0;
               for(int j = 1; j <= 6; j++)
                if((a[j]&(1LL<<i)) == 0)
                    z1 = z2, z2 = j;
               ops.push_back({a[set[cnt - 1]], a[z1], a[z2]});
               modify(set[cnt - 1], z1, z2, a);
           }
           set.clear(); cnt = 0;
           for(int j = 1; j <= n; j++) {
                cnt += ((a[j]&(1LL<<i)) > 0);
                if(((a[j]&(1LL<<i)) > 0))
                    set.push_back(j);
            }
           for(int j = 0; j < cnt - cnt%3; j+=3) {
               ops.push_back({a[set[j]], a[set[j + 1]], a[set[j + 2]]});
               modify(set[j], set[j + 1], set[j + 2], a);
           }
        }
        cout << ops.size() << "\n";
        for(int i = 0; i < ops.size(); i++) cout << get<0>(ops[i]) << " " << get<1>(ops[i]) << " " << get<2>(ops[i]) << "\n";
    }
    return 0;
}
*/
