/**
  * Author: Prasant Kumar Patel
  * Profiles:
  * 	Codeforces - prasantkpatel, 
  *		Codechef - mania_prashant, 
  *		AtCoder - prasantkpatel,
  * File Name: d.cpp
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

// Debugging template
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
#ifndef LOCAL
#define debug(...) 0
#define debugA(x, y) 0
#else
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define debugA(x, y) cerr << "[" << #x << "] = "; _printA(x, y)
#endif


void solve(int tc=1) {
	int n;
	cin >> n;

	vi a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	vector<pair<vector<int>, pair<int, int>>> b;
	vector<int> temp;
	for(int i = 0; i < n; ++i) {
		if(a[i] == 0)
			continue;

		temp.pb(a[i]);
		if(i + 1 >= n || a[i + 1] == 0) {
			if(!temp.empty())
				b.pb({temp, {i + 1 - sz(temp), n - i - 1}});
			temp.resize(0);
		}
	}

	int ax = 0, ay = n, pr = 0;
	for(auto [v, p] : b) {
		debug(v, p);
		int x = p.fi, y = p.se, c = 0, t = 0;
		for(auto num : v)
			c += (num < 0), t += (abs(num) == 2);
		if(c % 2 == 0) {
			if(t > pr)
				ax = x, ay = y, pr = t;
		
		} else {
			int sx = x, ey = y, st = t, et = t;
			for(int i = 0; i < sz(v); ++i) {
				++sx;
				st -= (abs(v[i]) == 2);
				if(v[i] < 0)
					break;
			}
			for(int i = sz(v) - 1; i >= 0; --i) {
				++ey;
				et -= (abs(v[i]) == 2);
				if(v[i] < 0)
					break;
			}
			if(st > pr)
				ax = sx, ay = y, pr = st;
			if(et > pr)
				ax = x, ay = ey, pr = et;
		}
	}
	cout << ax << " " << ay << nl;
	debug(pr);
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
