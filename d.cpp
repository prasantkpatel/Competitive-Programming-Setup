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

int get_xor(int l, int r) {
	if(l == r)
		return l;

	int res = (l % 2 ? l++ : 0);
	for(int j = r; j >= r + 1 - (r - l + 1) % 4; --j)
		res ^= j;

	return res;
}

// Binary Trie
template <typename T = int>
class BinaryTrie {
	private:
		struct node {
			node *left, *right;
			
			node() {
				left = right = nullptr;
			}
		};
		
		node* root;
		int n;
		
		void clear(node* _root) {
			if(_root == nullptr)
				return;
				
			clear(_root -> left);
			clear(_root -> right);
			
			delete _root;
		}
		
	public:
		BinaryTrie() {
			root = new node();
			n = sizeof(T) * CHAR_BIT;
		}
		
		~BinaryTrie() {
			clear(root);
		}
		
		void insert(T x) {
			node* temp = root;
			for(int i = n - 1; i >= 0; --i) {
				if(x & (1 << i)) {
					if(temp -> right == nullptr)
						temp -> right = new node();
					temp = temp -> right;
					
				} else {
					if(temp -> left == nullptr)
						temp -> left = new node();
					temp = temp -> left;
				}
			}
		}
		
		T max_xor(T x) {
			T res = 0;
			node* temp = root;

			for(int i = n - 1; i >= 0; --i) {
				assert(temp -> left != nullptr || temp -> right != nullptr);
				
				if(x & (1 << i)) {
					if(temp -> left != nullptr)
						res |= (1 << i), temp = temp -> left;
					else
						temp = temp -> right;
						
				} else {
					if(temp -> right != nullptr)
						res |= (1 << i), temp = temp -> right;
					else
						temp = temp -> left;
						
				}
			}
			return res;
		}

		T min_xor(T x) {
			T res = 0;
			node* temp = root;

			for(int i = n - 1; i >= 0; --i) {
				assert(temp -> left != nullptr || temp -> right != nullptr);
				
				if(x & (1 << i)) {
					if(temp -> right != nullptr)
						temp = temp -> right;
					else
						res |= (1 << i), temp = temp -> left;
						
				} else {
					if(temp -> left != nullptr)
						temp = temp -> left;
					else
						res |= (1 << i), temp = temp -> right;
						
				}
			}
			return res;
		}
};


void solve(int tc=1) {
	int l, r;
	cin >> l >> r;

	int n = r - l + 1;
	vi a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	int tot_xor = 0;
	for(auto x : a)
		tot_xor ^= x;

	if((r - l + 1) % 2) {
		cout << (tot_xor ^ get_xor(l, r)) << nl;
		return;
	}

	BinaryTrie<int> tr;
	for(auto x : a)
		tr.insert(x);

	for(auto x : a) {
		int is = tot_xor ^ x ^ get_xor(l + 1, r);
		if(tr.min_xor(is) == l && tr.max_xor(is) == r) {
			cout << is << nl;
			return;
		}		
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

	cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		//case_g(i);
		solve(i);
	}
	return 0;
}
