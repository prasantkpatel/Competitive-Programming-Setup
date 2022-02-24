// Libraries
#include <bits/stdc++.h>
#include <unistd.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Optimization
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

// Macros
#define nitro std::ios_base::sync_with_stdio(false), std::cin.tie(NULL)
#define FILE_IO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define case_g(x) cout<<"Case #"<<x<<": "
#define verdict(status) cout << ((status) ? "Yes" : "No") << nl;

// Aliases
using ll = long long;
using ld = long double;
using vi = std::vector<int>;
using vl = std::vector<ll>;
using vb = std::vector<bool>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using pib = std::pair<int, bool>;
using plb =  std::pair<ll, bool>;
using vii = std::vector<pii>;
using vll = std::vector<pll>;
using vib = std::vector<pib>;
using vlb = std::vector<plb>;
using vvi = std::vector<vi>;
using vvl = std::vector<vl>;
using vvb = std::vector<vb>;
using mapii = std::map<int, int>;
using mapll = std::map<ll, ll>;
using mapib = std::map<int, bool>;
using maplb = std::map<ll, bool>;
using ranked_pairset = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;
using ranked_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ranked_map = tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

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

// Constants
constexpr ll mod = 1000000007;
constexpr ld pi = 3.141592653589793L;
constexpr char nl = '\n';

// Random Stuff
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());

// Colours for fun :)
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// Don't ask me why, you just need it sometimes
template <typename T>
string bin(T x, int fixed = -1) {
	// Returns a binary of length equivalent to the no. of bits or "fixed"
	int n = sizeof(T) * CHAR_BIT;
	constexpr T one = 1;
	string res(n, '0'); 
	for(int i = 0; i < n; ++i)
		if(x & (one << i))
			res[i] = '1';
	
	if(fixed != -1)
		res = res.substr(0, fixed);
		
	reverse(all(res));
	return res;
}

void precompute() {
}

void solve(int tc = 1) {
	
}

int main() {
	nitro;
	
	int tc = 1;
 	cin >> tc;
	
	precompute();
	for(int i = 1; i <= tc; ++i) {
		//case_g(i);
		solve(i);
	}
	return 0;
}








