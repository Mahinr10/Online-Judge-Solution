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

char str[6000];
ull hs[6000];
ull rs[6000];
ull p = 1997;
ull pp[6000];
int dp[5001][5001];

int go(int i, int j){
    if(i == j){
        return 1;
    }
    if(i > j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int len = j - i + 1;
    ull h1 = hs[j] - (hs[i - 1] * pp[len]);
    ull h2 = rs[i] - (rs[j + 1] * pp[len]);
    int ans = 0;
    if(h1 == h2){
        ans = 1;
    }
    ans += (go(i + 1, j) + go(i, j - 1) - go(i + 1, j - 1));
    dp[i][j] = ans;
  //  dbg(i, j, ans, h1, h2)
    return ans;
}

int main(){
    #ifdef home
     freopen("input.txt", "r",stdin);
     //freopen("output.txt", "r",stdin);
    #endif // home
    memset(dp, -1, sizeof(dp));
    scanf("%s", str);
    int n = strlen(str);
    pp[0] = 1;
    for(int i = 1; i <= n; i++){
        hs[i] = (hs[i - 1] * p) + str[i - 1];
        pp[i] = p * pp[i - 1];
    }
    for(int i = n; i >= 1; i--){
        rs[i] = (rs[i + 1] * p) + str[i - 1];
    }
    int q; scanf("%d", &q);
    while(q--){
        int s, e;
        scanf("%d%d", &s, &e);
        int ans = go(s, e);
        printf("%d\n", ans);
    }



    return 0;



}
