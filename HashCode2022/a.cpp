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

map<string, int> contr, proj;

void precompute() {
}

struct ppl {
	string name;
	map<string, int> sk;
};

struct prj {
	string name;
	int dur, sc, bb, rc; // duration, score, best before, role count;
	vector<pair<string, int>> role; 
};

void solve(int tc=1) {
	int n, m;
	cin >> n >> m;
	vector<ppl> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].name;
		int skc;
		cin >> skc;
		for (int j = 0; j < skc; ++j) {
			string skn;
			int lev;
			cin >> skn >> lev;
			p[i].sk[skn] =  max(p[i].sk[skn], lev);
		}
	}
	vector<prj> q(m);
	for (int i = 0; i < m; ++i) {
		cin >> q[i].name >> q[i].dur >> q[i].sc >> q[i].bb >> q[i].rc;
		q[i].role.resize(q[i].rc);
		for (int j = 0; j < q[i].rc; ++j) {
			cin >> q[i].role[j].first >> q[i].role[j].second;
		}
	}

	map<string, vector<pair<int, string>>> role_map;
	map<string, int> idx_map;
	for(int i = 0; i < m; ++i) {
		idx_map[q[i].name] = i;
	}
	for(int i = 0; i < n; ++i) {
		for(auto [k, v] : p[i].sk) {
			role_map[k].push_back({v, p[i].name});
		}
	}

	vector<pair<string, vector<string>>> ans;
	int cur = 0;
	bool done[m + 1] = {};
	int break_when = 0;
	while(break_when++ <= 0) {
		map<string, bool> vis;
		for(int i = 0; i < m; ++i) {
			if(done[i])
				continue;

			bool ok = 1;
			vector<string> guys;
			for(auto [skill, level] : q[i].role) {
				pair<int, string> which = {420, "loda"};
				for(auto [guy_level, guy] : role_map[skill]) {
					if(vis[guy])
						continue;
					if(guy_level >= level && guy_level < which.fi) {
						which = {guy_level, guy};
					}
				}
				if(which.fi == 420) {
					ok = 0;

				} else {
					guys.push_back(which.se);
					vis[which.se] = 1;
				}
			}
			if(ok) {
				pair<string, vector<string>> tmp;
				tmp.fi = q[i].name;
				
				for(auto &guy : guys) {
					tmp.se.push_back(guy);
					for(auto [skill, level] : q[i].role) {
						for(auto &[guy_level, gui] : role_map[skill]) {
							if(gui == guy) {
								++guy_level;
								break;
							}
						}
					}
				}
				ans.pb(tmp);
				cur = max(cur, q[i].dur);
				done[i] = 1;
			}
		}
	}

	cout << sz(ans) << nl;
	for(auto &[project, contributors] : ans) {
		cout << project << nl;
		for(auto &guys : contributors) {
			cout << guys << " ";
		}
		cout << nl;
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
		solve(i);
	}
	return 0;
}
