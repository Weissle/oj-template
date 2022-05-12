#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 123
#endif

using namespace std;
using ll = long long;
const ll MAXN = 2e5+5;
using pii = pair<ll,ll>;
ll n,m,q;

void solve(){
	cin >> n;
	pii pai(5,6);
	vector<string> ps{"abc","deg"};
	vector<ll> p{5,6,7,34124235};
	set<int> se{143,457};
	map<int,string> mp{{123,"123"},{345,"345"}};
	debug(n,pai);
	debug(ps,p,se);
	debug(mp);

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int t=1;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
