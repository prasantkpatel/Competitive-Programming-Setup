/**
  * Author: Prasant Kumar Patel
  * Profiles:
  * 	Codeforces - prasantkpatel, 
  *		Codechef - mania_prashant1, 
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

// Colours for fun :)
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void precompute() {
}

// 2D Grid
template <typename T>
class grid {
private:
	int n, m;
	vector<vector<T>> mat;

	static constexpr int dx[4] = {1, -1, 0, 0};
	static constexpr int dy[4] = {0, 0, 1, -1};

public:
	grid(int _n, int _m) {
		n = _n, m = _m;
		mat.resize(n);
		for(auto &v : mat) {
			v.resize(m, T());
		}
	}

	vector<T>& operator[](int idx) {
		return mat[idx];
	}

	bool inline is_valid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n && j < m);
	}
	bool inline is_valid(pair<int, int> ix) {
		return is_valid(ix.first, ix.second);
	}

	vector<pair<int, int>> inline next(int i, int j) {
		vector<pair<int, int>> neighbours;
		for(int k = 0; k < 4; ++k) {
			int ix = i + dx[k], jx = j + dy[k];
			if(is_valid(ix, jx)) 
				neighbours.push_back({ix, jx});
		}
		return neighbours;
	}
	vector<pair<int, int>> inline next(pair<int, int> ix) {
		return next(ix.first, ix.second);
	}

	/* Gives the next node from (i, j) according to the direction.
	 * Valid directions are u and U for moving up. Rest three
     * directions are similar.
	*/
	pair<int, int> inline move(int i, int j, char dir) {
		pair<int, int> res;
		if(dir == 'U' || dir == 'u') {
			res = {i - 1, j};

		} else if(dir == 'D' || dir == 'd') {
			res = {i + 1, j};

		} else if(dir == 'L' || dir == 'l') {
			res = {i, j - 1};

		} else if(dir == 'R' || dir == 'r') {
			res = {i, j + 1};

		} else {
			cerr << "Error: invalid direction" << nl;
			res = {-1, -1};
		}
		return res;
	}
	pair<int, int> inline move(pair<int, int> ix, char dir) {
		return move(ix.first, ix.second, dir);
	}

	/* Gives the next node from (i, j) according to the direction.
	 * Valid directions are up, UP, uP, Up, u, and U for moving up. 
	 * Rest three directions are similar.
	*/
	pair<int, int> inline move(int i, int j, string dir) {
		for(auto &ch : dir)
			ch = tolower(ch);

		pair<int, int> res;
		if(dir == "up" || dir == "u") {
			res = {i - 1, j};

		} else if(dir == "down" || dir == "d") {
			res = {i + 1, j};

		} else if(dir == "left" || dir == "l") {
			res = {i, j - 1};

		} else if(dir == "right" || dir == "r") {
			res = {i, j + 1};

		} else {
			cerr << "Error: invalid direction" << nl;
			res = {-1, -1};
		}
		return res;
	}
	pair<int, int> inline move(pair<int, int> ix, string dir) {
		return move(ix.first, ix.second, dir);
	}
};

grid<bool> vis(1000, 1000);
void dfs(int i, int j) {
	if(vis[i][j])
		return;

	vis[i][j] = 1;
	for(auto [ix, jx] : vis.next(i, j))
		dfs(ix, jx);
}

void solve(int tc=1) {
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			char t; cin >> t;
			vis[i][j] = (t == '#');
		}

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(!vis[i][j]) {
				++ans;
				dfs(i, j);
			}
		}
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

 	//cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		//case_g(i);
		solve(i);
	}
	return 0;
}
