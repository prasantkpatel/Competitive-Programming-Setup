/**
  * Author: Prasant Kumar Patel
  * Profiles:
  *     Codeforces - prasantkpatel, 
  *        Codechef - mania_prashant1, 
  *        AtCoder - prasantkpatel,
  * File Name: b.cpp
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

void solve(int tc=1) {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    n = min(n, 10);
    a.resize(n);
    

    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j!=i){
                    for(int k=0; k<n; k++){
                        if(k!=j && k!=i){
                            for(int l=0; l<n; l++){
                                if(l!=i && l!=j && l!=k){
                                    if(__builtin_popcount(a[i]^a[j])==__builtin_popcount(a[k]^a[l])){
                                        cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1<<endl;
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    cout << -1 << nl;
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
