/**
  * Author: Prasant Kumar Patel
  * Profiles:
  * 	Codeforces - prasantkpatel, 
  *		Codechef - mania_prashant1, 
  *		AtCoder - prasantkpatel,
  * File Name: c.cpp
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

const int mxN = 2e5;
int LOG[mxN + 1] = {};
void precompute() {
	for(int i = 2; i <= mxN; ++i)
		LOG[i] = LOG[i / 2] + 1;
}
 
class sparse_table {
	private:
		int n, spS, identity = 0;
		vvi table;
		
	public:
		sparse_table(int _n) {
			n = _n, spS = LOG[n] + 1;
			table.resize(n);
			for(int i = 0; i < n; ++i)
				table[i].resize(spS, identity);
		}
		
		void build(vi &a) {
			for(int i = 0; i < n; ++i)
				table[i][0] = a[i];
			
			for(int j = 1; j < spS; ++j) {
				for(int i = 0; i + (1 << j) <= n; ++i) {
					table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
				}
			}
		}
		
		int query(int l, int r) {
			if(l < 0 || r < 0 || l >= n || r >= n || l > r)
				return identity;
			int len = r - l + 1, jx = LOG[len];
			return min(table[l][jx], table[r - (1 << jx) + 1][jx]);
		}
};

void solve(int tc=1) {
	int n, q;
	cin >> n >> q;

	vi a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sparse_table sps(n);
	sps.build(a);

	while(q--) {
		int l, r; cin >> l >> r;
		--l, --r;
		cout << sps.query(l, r) << nl;
	}
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
