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

typedef long long int ull;
typedef unsigned long long int ll;
// const double PI = 2.0*acos(0.0);
//const double GOLD = (1.0 + sqrt(5.0))/2.0;
//const double eps = 1e-9;

vector<int>ans;
char str[1000010], pat[1000010];
int pr[1000010];

void build_prefix(int m){
    pr[0] = 0;
    for(int i = 1; i < m; i++){
        int j = pr[i - 1];
        while(j > 0 && pat[j] != pat[i]){
            j = pr[j - 1];
        }
        if(pat[j] == pat[i]) ++j;
        pr[i] = j;
    }
}



int main(){
    #ifdef home
     freopen("input.txt", "r",stdin);
     //freopen("output.txt", "r",stdin);
    #endif // home

//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);

    int t; scanf("%d", &t);
    while(t--){
        scanf("%s%s",str,  pat);
        int n = strlen(str);
        int m = strlen(pat);
        build_prefix(m);
        ans.clear();
        dbgA(pr, m)
        for(int i = 0, j = 0; i < n; i++){
            if(str[i] != pat[j]){
                while(j > 0 && pat[j] != str[i])
                    j = pr[j - 1];
            }
            if(str[i] == pat[j])
                j++;
            if(j == m){
                ans.push_back(i - j + 1);
                j = pr[j - 1];
            }
        }
        if(ans.size() == 0){
            puts("Not Found\n");
            continue;
        }
        printf("%d\n", ans.size());
        for(int k : ans){
            printf("%d ", k + 1);
        }
        puts("\n");

    }

    return 0;

}
