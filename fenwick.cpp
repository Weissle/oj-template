// https://www.luogu.com.cn/problem/P3374

#include<bits/stdc++.h>

using namespace std;

using ll = long long;
int n,m,l,r;

template<typename T>
struct Fenwick{
	vector<T> p;
	int n,offset;
	Fenwick(int _n,int _offset){
		n = _n+1;
		offset = _offset;
		p.resize(n);
	}
	int lowbit(int x) {return x & (-x); }

	T query(int x){
		x += offset;
		T ret= 0;
		while(x){
			ret += p[x];
			x -= lowbit(x);
		}
		return ret;
	}

	void add(int x,T val){
		x += offset;
		while(x < n){
			p[x] += val;
			x += lowbit(x);
		}
	}

};

void solve(){
	cin >> n >> m;
	Fenwick<ll> fw(n,0);
	for (int i = 0; i < n; ++i){ 
		ll tmp; cin>>tmp;
		fw.add(i+1, tmp);
	}
	for (int i = 0; i < m; ++i){ 
		int op,a,b;
		cin >> op >> a>>b;
		if(op == 1) fw.add(a,b);
		else{
			ll l,r;
			l = fw.query(a-1);
			r = fw.query(b);
			cout<<r-l<<endl;

		}
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
