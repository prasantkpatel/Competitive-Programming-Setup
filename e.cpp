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

const ll INF = 1LL << 60;

void solve(int tc=1) {
	int n, m;
	cin >> n >> m;

	vector<array<int, 3>> e(m);
	for(int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		e[i] = {w, u, v};
	}

	sort(all(e));
	vector<pll> adj[n + 1];
	int ans = m;

	for(auto [w, u, v] : e) {
		vl d(n + 1, INF);
		bool vis[n + 1] = {};
		priority_queue<pll, vll, greater<pll>> q;

		d[u] = 0, q.push({d[u], u});
		while(!q.empty()) {
			auto [_d, _u] = q.top(); q.pop();
			if(vis[_u])
				continue;

			vis[_u] = 1;
			for(auto &[_w, _v] : adj[_u]) {
				d[_v] = min(d[_v], d[_u] + _w);
				q.push({d[_v], _v});
			}
		}

		if(d[v] == INF || d[v] > w) {
			adj[u].pb({w, v});
			adj[v].pb({w, u});
			--ans;
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

 	for(int i = 1; i <= tc; ++i) {
		//case_g(i);
		solve(i);
	}
	return 0;
}
