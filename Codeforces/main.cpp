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



int dp[2010][2010], n, h, l, r;
int ar[2010];
int go(int i, int s){
    if(i == n){
        return 0;
    }
    if(dp[i][s] != -1)
        return dp[i][s];


    int ns1 = (s + ar[i]) % h;
    int ns2 = (s + ar[i] - 1) % h;
    int g1 = go(i + 1, ns1);
    int g2 = go(i + 1, ns2);


    if(ns1 >= l && ns1 <= r){
        ++g1;
    }
    if(ns2 >= l && ns2 <= r){
        ++g2;
    }
    dp[i][s] = max(g1, g2);
   // dbg(s, i, dp[i][s]);

    return dp[i][s];

}

int main(){
    #ifdef home
     freopen("input.txt", "r",stdin);
     //freopen("output.txt", "r",stdin);
    #endif // home

    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d%d", &n, &h, &l, &r);
    forn(i, n){
        scanf("%d", ar + i);
    }

    int ans = go(0, 0);
    printf("%d\n", ans);



}

