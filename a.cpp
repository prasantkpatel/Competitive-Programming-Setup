/**
  * Author: Prasant Kumar Patel
  * Profiles:
  * 	Codeforces - prasantkpatel, 
  *		Codechef - mania_prashant1, 
  *		AtCoder - prasantkpatel,
  * File Name: a.cpp
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

// 2D Grid
template <typename T>
class grid {
private:
	struct node {
	private:
		T val;
		int i, j;
		vector<pair<int, int>> neighbours;

	public:
		node() {
			val = T();
			i = -1, j = -1;
		}

		void set(int _i, int _j) {
			i = _i;
			j = _j;
		}

		vector<pair<int, int>>& next() {
			return neighbours;
		}

		bool operator==(T x) {return val == x;}
		bool operator!=(T x) {return val != x;}
		T operator=(T x) {return (val = x);}
		T operator+(T x) {return val + x;}
		T operator-(T x) {return val - x;}
		T operator*(T x) {return val * x;}
		T operator/(T x) {return val / x;}
		T operator&&(T x) {return val && x;}
		T operator||(T x) {return val || x;}
		T operator^(T x) {return val ^ x;}
		T operator&(T x) {return val & x;}
		T operator|(T x) {return val | x;}
		T operator+=(T x) {return (val += x);}
		T operator-=(T x) {return (val -= x);}
		T operator*=(T x) {return (val *= x);}
		T operator/=(T x) {return (val /= x);}
		T operator++() {return (val++);}
		T operator--() {return (val--);}


		friend ostream& operator<<(ostream &o, node &obj) {
			o << obj.val;
			return o;
		}

		friend istream& operator>>(istream &i, node &obj) {
			i >> obj.val;
			return i;
		}

		/* Gives the next node from (i, j) according to the direction.
		 * Valid directions are u and U for moving up. Rest three
         * directions are similar.
		*/
		pair<int, int> operator[](char dir) {
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

		/* Gives the next node from (i, j) according to the direction.
		 * Valid directions are up, UP, uP, Up, u, and U for moving up. 
		 * Rest three directions are similar.
		*/
		pair<int, int> operator[](string dir) {
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
	};

	int n, m;
	vector<vector<node>> mat;

	static constexpr int dx[4] = {1, -1, 0, 0};
	static constexpr int dy[4] = {0, 0, 1, -1};

public:
	grid(int _n, int _m) {
		n = _n, m = _m;
		mat.resize(n);
		for(auto &v : mat) {
			v.resize(m, node());
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				for(int k = 0; k < 4; ++k) {
					if(is_valid(i + dx[k], j + dy[k])) {
						mat[i][j].next().push_back({i + dx[k], j + dy[k]});
						mat[i][j].set(i, j);
					}
				}
			}
		}
	}

	vector<node>& operator[](int idx) {
		return mat[idx];
	}

	bool is_valid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n && j < m);
	}
};

bool vis[1000][1000];
void dfs(grid<char> &a, int i, int j) {
	if(vis[i][j])
		return;

	vis[i][j] = 1;
	for(auto [ix, jx] : a[i][j].next()) {
		if(a[ix][jx] == '.')
			dfs(a, ix, jx);
	}
}

void solve(int tc=1) {
	int n, m;
	cin >> n >> m;

	grid<char> a(n, m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(a[i][j] == '.' && !vis[i][j]) {
				++ans;
				dfs(a, i, j);
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

	for(int i = 1; i <= tc; ++i) {
		//case_g(i);
		solve(i);
	}
	return 0;
}
