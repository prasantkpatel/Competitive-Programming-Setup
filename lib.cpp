// Disjoint Set Union - 1
class dsu {
private:
	vi p, rank;
public:
	dsu(int n) {
		p.assign(n, 0);
		rank.assign(n, 0);
		for (int i = 0;i < n;i++)
			p[i] = i;
	}
	int find(int a) {
		return p[a] == a ? a : p[a] = find(p[a]);
	}
	bool isSameSet(int a, int b) {
		return find(a) == find(b);
	}
	void un(int a, int b) {
		int x = find(a), y = find(b);
		rank[x] < rank[y] ? p[x] = y : p[y] = x;
		if (rank[x] == rank[y])
			rank[x]++;
	}
};


// Disjoint Set Union - 2
const int N = 2e5+1;

int p[N];

void build(int n) {
	for (int i = 0;i < n;i++)
		p[i] = i;
}

int findset(int a) {
	return p[a] == a ? a : p[a] = findset(p[a]);
}

void unionset(int a, int b) {
	p[findset(a)] = findset(b);
}


// Modulo Power and Modulo Inverse
ll modpow(ll a, ll b, ll MOD=mod) {
	ll p = 1;
	while (b > 0) {
		if (b & 1)
			p = p * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return p;
}

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

string print_int128(__int128 a) {
    if (a == 0) {
        return "0";
    }
    string s;
    bool neg = (a < 0);
    if (neg)
        a *= -1;
    while (a > 0) {
        s += (char)('0' + a % 10);
        a /= 10;
    }
    if (neg)
        s += '-';
    reverse(all(s));
    return s;
}

// Complete Search - Generating Permutation (2 methods)
vi permutation;
void search() {
	if (permutation.size() == n) {
		// process permutation
	}
	else {
		for (int i = 0; i < n; i++) {
			if (chosen[i])
				continue;
			chosen[i] = true;
			permutation.push_back(i);
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}

void search() {
	vector<int> permutationem ;
	for (int i = 0; i < n; i++)
		permutation.push_back(i);
	do {
		// process permutation
	} while (next_permutation(permutation.begin(),permutation.end()));
}


// Binary Indexed Tree - 1 indexing
const int N = 1e5+1; //size

ll t[N];

void add(int k, ll x) {
	while (k <= n) {
		t[k] += x;
		k += k&-k;
	}
}

ll sum(int k) {
	ll s = 0;
	while (k >= 1) {
		s += t[k];
		k -= k&-k;
	}
	return s;
}


// Bitwise Operation
void demo {
	int x = 5328; // 0000 0000 0000 0000 0001 0100 1101 0000
	__builtin_clz(x); // The number of zeros at the beginning of the number - 19
	__builtin_ctz(x); // The number of zeros at the end of the number - 4
	__builtin_popcount(x); // The number of ones in the number - 5
	__builtin_parity(x); // The parity (even or odd) of the number of ones - 1
}


// Bellman-Ford Algorithm - O(nm)
void BellmanFord() {
	for (int i = 1;i <= n;i++)
		distance[i] = INF;
	distance[x] = 0; // starting point
	for (int i = 1; i <= n - 1;i++) {
		for (auto e : edges) {
			ll a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a] + w);
		}
	}
}


// Dijkstra Algorithm - O(n + m log m)
void Dijkstra() {
	for (int i = 1;i <= n;i++)
		distance[i] = INF;
	distance[x] = 0;
	priority_queue<pll, vll, greater<pll>> Q;
	Q.push({0, x}); // starting point
	while (!Q.empty()) {
		int a = Q.top().second;
		Q.pop();
		if (processed[a])
			continue;
		processed[a] = 1;
		for (auto u : adj[a]) {
			ll b = u.first, w = u.second;
			if (distance[a] + w < distance[b]) {
				distance[b] = distance[a]+w;
				Q.push({distance[b], b});
			}
		}
	}
}


// Floyd-Warshall Algorithm - O(n^3)
void FloydWarshall() {
	ll d[n + 1][n + 1];
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++)
			d[i][j] = INF;
		d[i][i] = 0;
	}
	while (m--) {
		ll u, v, w;
		cin >> u >> v >> w;
		d[u][v] = min(d[u][v], w);
		d[v][u] = min(d[v][u], w);
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}


// (x^k) mod m = x^(k mod (m − 1)) mod m.


// LCA
void dfs(int u, int par = 0) {
	p[u][0] = par;
	for(auto v : adj[u]) {
		if(v == par) continue;
		d[v] = d[u] + 1;
		dfs(v, u);
	}
}

int ancs(int x, int k) {
	for(int i = 20; i >= 0; --i)
		if(k & (1 << i))
			x = p[x][i];
	return x;
}

int lca(int a, int b) {
	if(d[a] < d[b])
		swap(a, b);
	
	a = ancs(a, d[a] - d[b]);
	if(a == b)
		return a;
		
	int k = -1;
	for(int j = mxM; j > 0; j /= 2) {
		while(k + j <= mxM && p[a][k + j] != p[b][k + j])
			a = p[a][k + j], b = p[b][k + j];
	}
	return p[a][0];
}
 
int main() {
	fio;
	int n, q;
	cin >> n >> q;
	p[0][0] = p[1][0] = 0;
	for (int i = 2;i <= n;i++) {
		cin >> p[i][0];
		adj[p[i][0]].pb(i);
	}
	for (int j = 1;j < 18;j++)
		for (int i = 0;i <= n;i++)
			p[i][j] = p[p[i][j - 1]][j - 1];
	dfs();
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (d[a] < d[b])
			swap(a, b);
		a = ancs(a, d[a] - d[b]);
		for (int j = 17;j >= 0;j--) {
			if (p[a][j] == p[b][j])
				continue;
			a = p[a][j];
			b = p[b][j];	
		}
		if (a != b) {
			a = p[a][0];
		}
		cout << a << '\n';
	}
}


// Recurrence Relation using Matrix Multiplication

const int N = 6;
 
void multiply(ll a[N][N], ll b[N][N]) {
	ll c[N][N] = {};
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			for (int k = 0;k < N;k++)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			a[i][j] = c[i][j];
}
 
void matpow(ll a[N][N], ll b) {
	ll p[N][N] = {};
	for (int i = 0;i < N;i++)
		p[i][i] = 1;
	while (b > 0) {
		if (b & 1)
			multiply(p, a);
		multiply(a, a);
		b >>= 1;
	}
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			a[i][j] = p[i][j];
}


// Tree Diameter

const int N = 2e5+1;
vi adj[N];
 
pii dfs(int u = 1, int p = 0) {
	pii a = {-1, u};
	for (auto v : adj[u])
		if (v != p)
			a = max(a, dfs(v, u));
	return {a.fi + 1, a.se};
}

int diameter = dfs(dfs().se).fi;

// Segment Tree
template <typename node, typename update>
class segment_tree {
	private:
		/*** 
		 * t: A sequence of tree nodes.
		 * 
		 * u: A sequence of tree updates.
		 * 
		 * lazy: A sequence of flags to check if there are 
		 * any pending updates on a node.
		 * 
		 * n: The size of segment tree
		 * 
		 * node_identity: An identity element for a tree node such 
		 * that combining any node with node_identity results in
		 * node itself.
		 * 
		 * update_identity: An identity element for an update node 
		 * such that applying such update to a node leaves the node
		 * unchanged. Also, combining any update with the update_identity 
		 * results in update itself.
		 * 
		 **/
		vector<node> t;
		vector<update> u;
		vector<bool> lazy;
		int n;
		node node_identity;
		update update_identity;
		
		template <typename T>
		void build(const T &a, const int32_t k, const int32_t tl, const int32_t tr) {
			if(tl > tr) return;
			if(tl == tr) {
				t[k] = node(a[tl]);
				return;
			}
			
			const int32_t tm = (tl + tr) >> 1;
			build(a, k << 1, tl, tm);
			build(a, k << 1 | 1, tm + 1, tr);
			
			t[k].combine(t[k << 1], t[k << 1 | 1]);
		}
		
		node query(const int32_t k, const int32_t tl, const int32_t tr, const int32_t l, const int32_t r) {
			if(tl > tr || l > r || l < tl || r > tr)
				return node_identity;
			if(tl == l && tr == r)
				return t[k];
			
			push(k, tl, tr);
			const int32_t tm = (tl + tr) >> 1;
			node res;
			if(r <= tm)
				res = query(k << 1, tl, tm, l, r);
			else if(l > tm)
				res = query(k << 1 | 1, tm + 1, tr, l, r);
			else
				res.combine(query(k << 1, tl, tm, l, tm),
				query(k << 1 | 1, tm + 1, tr, tm + 1, r));
			
			return res;
		}
		
		void upd(const int32_t k, const int32_t tl, const int32_t tr, const int32_t l, const int32_t r, const update x) {
			if(tl > tr || l > r || l < tl || r > tr) 
				return;
			if(tl == l && tr == r) {
				apply(k, tl, tr, x);
				return;
			}
			
			push(k, tl, tr);
			const int32_t tm = (tl + tr) >> 1;
			if(r <= tm)
				upd(k << 1, tl, tm, l, r, x);
			else if(l > tm)
				upd(k << 1 | 1, tm + 1, tr, l, r, x);
			else
				upd(k << 1, tl, tm, l, tm, x),
				upd(k << 1 | 1, tm + 1, tr, tm + 1, r, x);
			
			t[k].combine(t[k << 1], t[k << 1 | 1]);
		}
		
		void push(const int32_t k, const int32_t tl, const int32_t tr) {
			if(!lazy[k])
				return; // no updates pending
				
			const int32_t tm = (tl + tr) >> 1;
			apply(k << 1, tl, tm, u[k]);
			apply(k << 1 | 1, tm + 1, tr, u[k]);
			
			lazy[k] = 0;
			u[k] = update_identity;
		}
		
		void apply(const int32_t k, const int32_t tl, const int32_t tr, const update x) {
			t[k].apply(x, tl, tr);
			if(tl == tr) return;
			
			u[k].combine(x, tl, tr);
			lazy[k] = 1;
		}
		
	public:
		segment_tree(int N) {
			t.resize(4 * N);
			u.resize(4 * N);
			lazy.resize(4 * N);
			n = N;
			node_identity = node();
			update_identity = update();
		}
		
		// Add extra methods if necessary
		node query(const int32_t l, const int32_t r) {
			return query(1, 0, n - 1, l, r);
		}
		template <typename T>
		void build(const T &a) {
			build(a, 1, 0, n - 1);
		}
		void upd(const int32_t l, const int32_t r, const update x) {
			upd(1, 0, n - 1, l, r, x);
		}
};
// Generic Update and Node structures
struct update {
	ll a = 0;
	
	update() {};
	update(ll a) {
	};
	
	void combine(const update x, int tl, int tr) {
	}
};

struct node {
	ll s = 0;
	
	node() {}
	node(ll x) {
	}
	
	void combine(const node a, const node b) {
	}
	
	void apply(const update x, int tl, int tr) {
	}
};


// Update and Node structures for (Range Sum, Update and Add) 
struct update {
	ll add = 0, set = 0;
	
	update() {};
	update(pll u) {
		add = u.fi;
		set = u.se;
	};
	
	void combine(const update &x) {
		if(x.set != 0) {
			add = 0;
			set = x.set;
		}
		if(x.add != 0) {
			if(set != 0)
				set += x.add;
			else
				add += x.add;
		}
	}
};

struct node {
	ll s = 0;
	
	node() {}
	node(ll x) {
		s = x;
	}
	
	void combine(const node &a, const node &b) {
		s = a.s + b.s;
	}
	
	void apply(const update &x, int tl, int tr) {
		s += (tr - tl + 1) * x.add;
		if(x.set != 0)
			s = (tr - tl + 1) * x.set;
	}
};

// Trie
class Trie {
	// TODO: Add a destructor to prevent memory leaks
	private:
		struct node {
			bool isTerminal;
			node *next[26];
			int _count;
			
			node() {
				for(int i = 0; i < 26; ++i)
					next[i] = nullptr;
				isTerminal = false;
				_count = 0;
			}
		};
		
		node *root;

		void clear(node *_root) {
			if(_root == nullptr)
				return;

			for(int i = 0; i < 26; ++i) {
				clear(_root -> next[i]);
			}
			delete _root;
		}
		
	public:
		Trie() {
			root = new node();
		}

		~Trie() {
			clear(root);
		}

		void insert(const string &s) {
			if(isPresent(s))
				return;
				
			node *temp = root;
			for(char c : s) {
				++temp -> _count;
				if(temp -> next[c - 'a'] == nullptr)
					temp -> next[c - 'a'] = new node;
				temp = temp -> next[c - 'a'];
			}
			
			temp -> isTerminal = true;
			++temp -> _count;
		}
		
		bool isPresent(const string &s) {
			node *temp = root;
			for(char c : s) {
				if(temp -> next[c - 'a'] == nullptr)
					return false;
				temp = temp -> next[c - 'a'];
			}
			return temp -> isTerminal;
		}
};

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
		
		node *root;
		int n;
		
		void clear(node *_root) {
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
			bool bits[n] = {};
			for(int i = 0; i < n; ++i) 
				bits[i] = x % 2, x /= 2;
			
			node *temp = root;
			for(int i = n - 1; i >= 0; --i) {
				if(bits[i]) {
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
			bool bits[n] = {};
			for(int i = 0; i < n; ++i)
				bits[i] = x % 2, x /= 2;
			
			node *temp = root;
			for(int i = n - 1; i >= 0; --i) {
				assert(temp -> left != nullptr || temp -> right != nullptr);
				
				if(bits[i]) {
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
};
