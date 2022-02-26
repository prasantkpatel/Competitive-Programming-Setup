template<typename T>
class sparse_table {
private:
	inline static int LOG(int n) {
		return sizeof(int) * CHAR_BIT - __builtin_clz(n) - 1;
	}

	struct op {
	private:
		T __identity;
		function<T(T, T)> __combinator;
		bool __is_overlap_agnostic; // true if queries can be answered by overlapping ranges

	public:
		op() {}
		op(T _identity, function<T(T, T)> _combinator, bool _is_overlap_agnostic) {
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

	vector<vector<T>> table;
	int n, spS;
	op operation;

public:
	struct use {
	public:
		const static inline op MIN = op(numeric_limits<T>::max(), [](const T &x, const T &y) {return min(x, y);}, true);
		const static inline op MAX = op(numeric_limits<T>::min(), [](const T &x, const T &y) {return max(x, y);}, true);
		const static inline op GCD = op(T(0), [](const T &x, const T &y) {return __gcd(x, y);}, true);
		const static inline op SUM = op(T(0), [](const T &x, const T &y) {return x + y;}, false);
		const static inline op XOR = op(T(0), [](const T &x, const T &y) {return x ^ y;}, false);
		const static inline op AND = op(T(1), [](const T &x, const T &y) {return x & y;}, true);
		const static inline op OR = op(T(0), [](const T &x, const T &y) {return x | y;}, true);
	};

	sparse_table(const op &_operation) {
		n = 0, spS = 0;
		operation = _operation;
	}

	sparse_table(function<T(T, T)> _combinator, T _identity, bool _is_overalp_agnostic) {
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

	void build(vector<T> &a) {
		n = max(n, (int)a.size());
		spS = LOG(n);

		table.resize(n);
		for(int i = 0; i < n; ++i) {
			table[i].resize(spS + 1, operation.identity());
		}

		for(int i = 0; i < (int)a.size(); ++i) {
			table[i][0] = a[i];
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
