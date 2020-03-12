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

pair<int, int> ar[1001][1001];
vector<pair<int, int> >g[1001][1001];
queue<pair<int, int> >q;
int visi[1001][1001];
char ans_str[1001][1001];

int main(){
    #ifdef home
     freopen("input.txt", "r",stdin);
     //freopen("output.txt", "r",stdin);
    #endif // home

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;


    forn(i, n){
        forn(j, n){
            ans_str[i][j] = 'P';
         //   cout << ans_str[i][j];
        }
    }
    forn(i, n){
        forn(j, n){
            int x, y;
            cin>>x>>y;
            ar[i][j] = {max(-1, x - 1), max( -1, y - 1)};

        }
    }
    forn(i, n){
        forn(j, n){
            if(ar[i][j] == make_pair(i, j)){
                ans_str[i][j] = 'X';
                q.push(make_pair(i, j));
                visi[i][j] = 1;
                continue;
            }
         //   dbg(i, j)

            /// move Left
            int x = i;
            int y = j - 1;

            if(x >= 0 && x < n && y >= 0 && y < n){
              //  continue;

                if(ar[i][j] == make_pair(-1, -1) && ar[i][j] == ar[x][y]){
                    dbg(i, j, x, y)
                    ans_str[i][j] = 'L';
                    continue;
                }
                else if(ar[i][j] == ar[x][y]){

                    g[i][j].push_back(make_pair(x, y));
                    g[x][y].push_back(make_pair(i, j));
//                    cnt[make_pair(i, j)]++;
                }
            }

            /// move Right
            x = i;
            y = j + 1;


            if(x >= 0 && x < n && y >= 0 && y < n){


                if(ar[i][j] == make_pair(-1, -1) && ar[i][j] == ar[x][y]){
                    ans_str[i][j] = 'R';
                    dbg(i, j, x, y)
                    continue;
                }
                else if(ar[i][j] == ar[x][y]){
                    g[i][j].push_back(make_pair(x, y));
                    g[x][y].push_back(make_pair(i, j));

        //            dbg(i, j, x, y)
//                    cnt[make_pair(i, j)]++;
                }
            }

            /// move Up
            x = i - 1;
            y = j;

            if(x >= 0 && x < n && y >= 0 && y < n){


                if(ar[i][j] == make_pair(-1, -1) && ar[i][j] == ar[x][y]){
                    dbg(i, j, x, y)
                    ans_str[i][j] = 'U';
                    continue;
                }
                else if(ar[i][j] == ar[x][y]){
                   // dbg(i, j, x, y)
                    g[i][j].push_back(make_pair(x, y));
                    g[x][y].push_back(make_pair(i, j));
//                    cnt[make_pair(i, j)]++;
                }
            }

            /// move Down
            x = i + 1;
            y = j;

            if(x >= 0 && x <= n && y >= 0 && y < n){


                if(ar[i][j] == make_pair(-1, -1) && ar[i][j] == ar[x][y]){
                    dbg(i, j, x, y)
                    ans_str[i][j] = 'D';
                    continue;
                }
                else if(ar[i][j] == ar[x][y]){
                    g[i][j].push_back(make_pair(x, y));
                    g[x][y].push_back(make_pair(i, j));
//                    cnt[make_pair(x, y)]++;
                }
            }


        }
    }

//    for(auto t : cnt){
//        dbg(t.first.first, t.first.second, t.second);
//        if(t.second == 1){
//            q.push(t.first);
//        }
//    }

    while(!q.empty()){
        auto u = q.front();
        q.pop();
      //  dbg(u.first, u.second)
        for(auto v: g[u.first][u.second]){
        //        dbg(v.first, v.second)
            if(visi[v.first][v.second] == 0){
                visi[v.first][v.second] = 1;
                q.push(v);
                int x = v.first;
                int y = v.second;
                dbg(x, y)
                if(x > u.first)
                    ans_str[x][y] = 'U';
                if(x < u.first)
                    ans_str[x][y] = 'D';
                if(y < u.second)
                    ans_str[x][y] = 'R';
                if(y > u.second)
                    ans_str[x][y] = 'L';
            }

        }
    }

    //dbgA2(ans_str, n, n)
    forn(i, n){
        forn(j, n){
            if(ans_str[i][j] == 'P'){
                cout << "INVALID" << endl;
                return 0;
            }
        }
    }

    cout << "VALID" << endl;
   // dbg(n)
    forn(i, n){
        forn(j, n){
            cout << ans_str[i][j];
        }
        cout << endl;
    }




}

