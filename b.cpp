/**
  * Author: Prasant Kumar Patel
  * Profiles:
  *     Codeforces - prasantkpatel, 
  *        Codechef - mania_prashant, 
  *        AtCoder - prasantkpatel,
  * File Name: b.cpp
*/

// Libraries
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

// Optimization
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

// Macros
#define nitro std::ios_base::sync_with_stdio(false), std::cin.tie(NULL)
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define case_g(x) cout<<"Case #"<<x<<": "

// Debugging template
#ifndef LOCAL
#define cerr if (false) cerr
#endif
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template<typename T>
void _printA(T *t, long long sz) { cout<<" { "; for (long long i=0; i<sz; i++) cout<<"["<<i<<"] = "<< t[i]<<endl; cout<<" } \n";}
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define debugA(x, y) cerr << "[" << #x << "] = "; _printA(x, y)


// Aliases
using ll = long long;
using ld = long double;
using vi = std::vector<int>;
using vl = std::vector<ll>;
using vb = std::vector<bool>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using vii = std::vector<pii>;
using vll = std::vector<pll>;
using vvi = std::vector<vi>;
using vvl = std::vector<vl>;
using vvb = std::vector<vb>;

// Constants
constexpr ll mod = 1000000007;
constexpr ld pi = 3.141592653589793L;
constexpr char nl = '\n';

// Colours for fun :)
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void precompute() {
}

void solve(int tc=1) {
    debug(tc);
    int n, c;
    cin >> n >> c;

    vi a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    c = *max_element(all(a));

    int kitne[2*c + 1] = {};
    for(auto x : a)
        kitne[x] = 1;

    for(int i = 1; i <= 2*c; ++i)
        kitne[i] += kitne[i - 1];

    for(auto x : a) {
        for(int j = 1; j <= (c / x); ++j) {
            debug(j*x, (j + 1)*x - 1);
            debug(kitne[(j + 1)*x - 1] - kitne[j*x - 1]);
            if((kitne[(j + 1)*x - 1] - kitne[j*x - 1]) && (kitne[j] - kitne[j - 1])) {
                cout << "No" << nl;
                return;
            }
        }
    }
    cout << "Yes" << nl;
}

int main() {
    nitro;
    
    #ifdef USE_IO_FILES
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    precompute();

    int tc = 1;

     cin >> tc;
    for(int i = 1; i <= tc; ++i) {
        //case_g(i);
        solve(i);
    }
    return 0;
}
