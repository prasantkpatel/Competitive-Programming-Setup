/**
  * Author: Prasant Kumar Patel
  * Profiles:
  * 	Codeforces - prasantkpatel, 
  *		Codechef - mania_prashant, 
  *		AtCoder - prasantkpatel,
  * File Name: e.cpp
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
constexpr ll mod = 998244353;
constexpr ld pi = 3.141592653589793L;
constexpr char nl = '\n';

// Colours for fun :)
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// Binary Indexed Tree - 1 indexing
const int mxN = 2e5 + 1; //size

ll f[mxN], fact[mxN], t[mxN];

void add(int k, ll x) {
	while (k <= mxN) {
		f[k] += x;
		k += k&-k;
	}
}

ll sum(int k) {
	ll s = 0;
	while (k >= 1) {
		s += f[k];
		k -= k&-k;
	}
	return s;
}

ll get(int l, int r) {
	return sum(r) - sum(l - 1);
}

// Modular Inverse
ll modinv(ll a, ll MOD=mod) {
	ll m = MOD, y = 0, x = 1;
	while (a > 1) {
		ll q = a / m, t = m;
		m = a % m;
		a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	return x < 0 ? x + mod : x;
}

void precompute() {
	fact[0] = 1;
	for(int i = 1; i < mxN; ++i)
		fact[i] = (fact[i - 1] * i) % mod;
}

void solve(int tc=1) {
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		add(x, 1);
	}

	vi a(m);
	for(int i = 0; i < m; ++i)
		cin >> a[i];

	ll fct = fact[n - 1];
	for(int i = 1; i <= mxN; ++i)
		fct = fct * modinv(fact[get(i, i)]) % mod;

	for(int i = 0; i < min(n, m); ++i)
		++t[a[i]];

	ll ans = (n < m);
	for(int i = 0; n < m && i < n; ++i) {
		ans = (ans && (get(a[i], a[i]) == t[a[i]]));
	}
	for(int i = 0; i < min(n, m); ++i) {
		debug(i + 1, fct, fct * get(1, a[i] - 1) % mod);
		ans = (ans + fct * get(1, a[i] - 1) % mod) % mod;
		fct = fct * modinv(n - i - 1) % mod;
		fct = fct * get(a[i], a[i]) % mod;
		add(a[i], -1);
	}

	cout << ans << nl;
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

 	for(int i = 1; i <= tc; ++i) {
		//case_g(i);
		solve(i);
	}
	return 0;
}
