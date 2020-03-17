# include <bits/stdc++.h>
using namespace std;
 
# define forn(i, n) for(int i = 0; i < n; i++)
# define fort(i, n) for(int i = 1; i <= n; i++)
# define all(x)     x.begin(), x.end()
 
# ifdef home
    # define dbg(args...)    {string sss(#args);sss+=',';cerr<<"-->";debugger::call(all(sss), args);cerr<<"\n";}
    # define dbgA(A, n)      {cerr<<"-->"<<#A<<"=(";forn(i, n)cerr<<A[i]<<" ";cerr<<")\n";}
    # define dbgA2(A, n, m)  {cerr<<"-->"<<#A<<"=\n";forn(i, n){forn(j, m){cerr<<setw(4)<<A[i][j]<<" ";}cerr<<"\n";}cerr<<"\n";}
# else
    # define dbg(args...)    234;
    # define dbgA(A, n)      456;
    # define dbgA2(A, n, m)  123;
# endif
 
struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
            string b;
        for(; *it!=','; ++it) if(*it!=' ')b+=*it;
        cerr << b << " = " << a << " ";
        call(++it, ed, rest...);
    }
};
 
//int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
//int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//int knight_x[] = {2, 2, -2, -2, 1, 1, -1, -1};
//int knight_y[] = {1, -1, 1, -1, 2, -2, 2, -2};
 
typedef long long int ll;
typedef unsigned long long int ull;
// const double PI = 2.0*acos(0.0);
//const double GOLD = (1.0 + sqrt(5.0))/2.0;
//const double eps = 1e-9;
 
 
int cnt = 0;
vector<int>g[200010];
map<pair<int, int>, int> mp;
 
void dfs(int s, int p = -1){
    for(int t : g[s]){
        if(t == p){
            continue;
        }
        dfs(t, s);
        mp[make_pair(min(s, t), max(s, t))] = cnt;
        ++cnt;
    }
}
 
vector<pair<int, int> > edge;
 
int e[200010];
int enq[200010];
int visi[200010];
queue<int>q;
 
int main(){
    #ifdef home
     freopen("input.txt", "r",stdin);
     //freopen("output.txt", "r",stdin);
    #endif // home
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    forn(i, n - 1){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        e[u]++;
        e[v]++;
        edge.push_back(make_pair(min(u, v), max(u, v)));
    }
 
    fort(i, n){
        if(e[i] == 1){
            q.push(i);
            enq[i] = 1;
        }
    }
    while(!q.empty()){
        int u = q.front();
        visi[u] = 1;
        q.pop();
        for(int v : g[u]){
            if(visi[v] == 1){
                continue;
            }
            //enq[v] = 1;
            int _u = min(u, v);
            int _v = max(u, v);
            if(enq[v] == 0){
                q.push(v);
                enq[v] = 1;
            }
            mp[make_pair(_u, _v)] = cnt;
            ++cnt;
            //dbg(cnt, _u, _v)
        }
    }
    forn(i, n - 1){
        cout << mp[edge[i]] << "\n";
    }
 
}
