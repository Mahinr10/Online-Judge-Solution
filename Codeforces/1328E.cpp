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

vector<int> g[200010];
int ht[300011];
int pr[200010];
int foc[200010];
int tr[4000010];
vector<int>eu;

int mins(int a, int b){
    if(ht[a] <= ht[b])
        return a;
    return b;
}

void build(int p, int l, int r){
    if(l == r){
        tr[p] = eu[l];
        return ;
    }
    int m = (l + r)/2;
    build(p * 2 + 1, l, m);
    build(p * 2 + 2, m + 1, r);
    tr[p] = mins(tr[p * 2 + 1], tr[p * 2 + 2]);
}

int query(int p, int L, int R, int l, int r){

    if(L > r || R < l)
        return 300010;
    if(l <= L && r >= R){
        return tr[p];
    }
    int m = (L + R)/2;
    int x = query(p * 2 + 1, L, m, l, r);
    int y = query(p * 2 + 2, m + 1, R, l, r);
//    dbg(l, r, x, y, m)
    return mins(x, y);
}

void dfs(int s, int d, int p = -1){
    eu.push_back(s);
    foc[s] = eu.size() - 1;
    ht[s] = d;
    pr[s] = p;
    for(int t : g[s]){
        if(t == p)
            continue;
        dfs(t, d + 1, s);
        eu.push_back(s);
    }

}

bool cmp(int a, int b){
    return ht[a] < ht[b];
}

int lca(int u, int v){
    return query(0, 0, eu.size() - 1, min(foc[u], foc[v]), max(foc[u], foc[v]));
}



int main(){
    #ifdef home
     freopen("input.txt", "r",stdin);
     //freopen("output.txt", "r",stdin);
    #endif // home

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin>>n>>q;
    ht[300010] = 300010;
    forn(i, n - 1){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    pr[1] = 1;
    build(0, 0, eu.size() - 1);
    dbgA(eu, eu.size());
    forn(k, q){
        int p; cin>>p;
        vector<int>r(p);
        forn(i, p){
            cin>>r[i];
            r[i] = pr[r[i]];
        }
        sort(all(r));
        r.resize(unique(all(r)) - r.begin());
        dbgA(r, r.size())
        sort(all(r), cmp);
        dbgA(r, r.size())
        bool ok = true;
        forn(i, r.size() - 1){
            if(lca(r[i], r[i + 1]) != r[i]){
                int ff = lca(r[i], r[i + 1]);
                dbg(ff, r[i], r[i + 1])
                dbg(foc[7], foc[9])
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }


}
