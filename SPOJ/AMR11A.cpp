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

ll ar[502][502];
ll need[502][502];
ll has[502][502];

int main(){

    #ifdef home
        freopen("input.txt", "r", stdin);
    #endif // home

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        fort(i, n){
            fort(j, m){
                cin>>ar[i][j];
            }
        }
        need[n][m] = 0;
        for(int i = n; i > 0; i--){
            for(int j = m; j > 0; j--){
                if(i == n && j == m){
                    need[i][j] = 0;
                }
                else if(i == n){
                    need[i][j] = min(0LL, ar[i][j] + need[i][j + 1]);
                }
                else if(j == m){
                    need[i][j] = min(0LL, ar[i][j] + need[i + 1][j]);
                }
                else{
                    ll x = min(0LL, ar[i][j] + need[i][j + 1]);
                    ll y = min(0LL, ar[i][j] + need[i + 1][j]);
                    need[i][j] = max(x, y);
                }
            }
        }
        dbgA2(need, n + 1, m + 1);
        dbg(need[1][1]);
        ll ans = abs(need[1][1]) + 1;
        dbg(ans)
        cout << ans << endl;
    }



    return 0;




}
