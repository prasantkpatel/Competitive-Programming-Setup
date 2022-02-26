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

template <typename T>
class sparse_table {
private:
	inline static int LOG(int n) {
		return sizeof(int) * CHAR_BIT - __builtin_clz(n) - 1;
	}

	template <typename F>
	struct op {
	private:
		T __identity;
		F __combinator;
		bool __is_overlap_agnostic; // true if queries can be answered by overlapping ranges
	
	public:
		op() {}
		op(T _identity, F _combinator, bool _is_overlap_agnostic) {
			__identity = _identity;
			__combinator = _combinator;
			__is_overlap_agnostic = _is_overlap_agnostic;
		}

		T combine(const T &x, const T &y) {
			return __combinator(x, y);
		}

		T identity() {
			return __identity;
		}

		bool is_overlap_agnostic() {
			return __is_overlap_agnostic;
		}
	};

	enum operations {
		MIN, MAX, GCD, SUM, XOR, AND, OR, NOP
	};

	// struct MIN {
	// private:
	// 	auto static min_func = [](const T &x, const T &y){return min(x, y);};
	// 	const static op<decltype(min_func)> MIN = op(numeric_limits<T>::max(), min_func, true);

	// public:
	// 	auto assign() {
	// 		return op;
	// 	}
	// 	const static inline op MAX = op(numeric_limits<T>::min(), [](const T &x, const T &y) {return max(x, y);}, true);
	// 	const static inline op GCD = op(T(0), [](const T &x, const T &y) {return __gcd(x, y);}, true);
	// 	const static inline op SUM = op(T(0), [](const T &x, const T &y) {return x + y;}, false);
	// 	const static inline op XOR = op(T(0), [](const T &x, const T &y) {return x ^ y;}, false);
	// 	const static inline op AND = op(T(1), [](const T &x, const T &y) {return x & y;}, true);
	// 	const static inline op OR = op(T(0), [](const T &x, const T &y) {return x | y;}, true);
	// };

	auto static min_func = [](const T &x, const T &y) {return min(x, y);};
	const static inline 
	vector<vector<T>> table;
	int n, spS, which;

public:
	static operations use;

	sparse_table(const operations _which) {
		n = 0, spS = 0, which = static_cast<int>(_which);
	}

	sparse_table(T _identity, function<T(T, T)> _combinator, bool _is_overalp_agnostic) {
		n = 0, spS = 0;
		operation = op(_identity, _combinator, _is_overalp_agnostic);
	}

	void build(int _n) {
		n = _n;
		spS = LOG(n);

		table.resize(n);
		for(int i = 0; i < n; ++i) {
			table[i].resize(spS + 1, operation.identity());
		}
	}

	template <typename V>
	void build(vector<V> &a) {
		n = max(n, (int)a.size());
		spS = LOG(n);

		table.resize(n);
		for(int i = 0; i < n; ++i) {
			table[i].resize(spS + 1, operation.identity());
		}

		for(int i = 0; i < (int)a.size(); ++i) {
			table[i][0] = static_cast<T>(a[i]);
		}

		for(int j = 1; j <= spS; ++j) {
			for(int i = 0; i + (1 << j) <= (int)a.size(); ++i) {
				table[i][j] = operation.combine(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	T query(int l, int r) {
		T res = operation.identity();
		if(l < 0 || r < 0 || l >= n || r >= n || l > r) {
			cerr << "Error: invalid range [" << l << ", " << r << "] in query to sparse table" << nl;

		} else if(operation.is_overlap_agnostic()) {
			res = operation.combine(table[l][LOG(r - l + 1)], table[r - (1 << LOG(r - l + 1)) + 1][LOG(r - l + 1)]);
			
		} else {
			while(l <= r) {
				res = operation.combine(res, table[l][LOG(r - l + 1)]);
				l += 1 << LOG(r - l + 1);
			}
		}
		return res;
	}
};

void solve(int tc=1) {
	int n, q;
	cin >> n >> q;

	vi a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sparse_table<ll> sps(sparse_table<ll>::use::SUM);
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
