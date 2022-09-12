/*
 * author: weissle
 * create: Sun May 22 21:24:50 2022
*/
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
ll p[MAXN];

template<typename T, T default_val>
struct SegmentTreeNode{
	ll l,r;
	int lidx=-1,ridx=-1;
	T val=default_val;
	T lazy_val;
	bool lazy=false;
	SegmentTreeNode(ll l_, ll r_):l(l_),r(r_){}
	SegmentTreeNode(){}
};

template<typename T, T default_val>
struct SegmentTree{
	using SNode = SegmentTreeNode<T,default_val>;
	vector<SNode> p;
	int n,num,left,right;
	function<void(T&,T)> update_val_policy;
	function<T(int ,T)> update_lazy_policy;
	function<void(T&,T)> query_val_policy;
	function<T(int ,T)> query_lazy_policy;
	SegmentTree(int left_,int right_,int node_num, function<void(T&, T)> update_val_policy_, 
			function<void(T&, T)> query_val_policy_, function<T(int, T)> query_lazy_policy_ ):
		left(left_), right(right_), update_val_policy(update_val_policy_),query_val_policy(query_val_policy_), query_lazy_policy(query_lazy_policy_)
	{ 
		p.resize(node_num);
		num=1;
		p[0] = SNode(left_,right_);
	}

	void update(int idx, int val){
		range_update(idx,idx,val);
	}

	void range_update(int l, int r, int val){
		_update(l,r,val,0);
	}
	
	T range_query(ll l, ll r){
		return _query(l,r,0);
	}

private:
	void _update(ll l, ll r, ll val, int nidx){
		SNode &node = p[nidx];
		ll rangel =  node.l, ranger = node.r;
		if(r<rangel || l > ranger) return;
		if(l<=rangel && r>= ranger){
			if(node.lazy==false) {
				node.lazy=true;
				node.lazy_val = default_val;
			}
			update_val_policy(node.lazy_val, val);
			return;
		}
		if(node.lidx == -1){
			assert(node.ridx == -1);
			ll mid = (rangel+ranger)/2;
			node.lidx = num++;
			node.ridx = num++;
			p[node.lidx] = SNode(rangel,mid);
			p[node.ridx] = SNode(mid+1,ranger);
		}
		if(node.lazy){
			_update(rangel,ranger,node.lazy_val,node.lidx);
			_update(rangel,ranger,node.lazy_val,node.ridx);
			node.lazy = false;
		}
		_update(l,r,val,node.lidx);
		_update(l,r,val,node.ridx);
		node.val = default_val;
		update_val_policy(node.val,_query(rangel, ranger, node.lidx));
		update_val_policy(node.val,_query(rangel, ranger, node.ridx));
	}

	T _query(ll l, ll r, int nidx){
		SNode &node = p[nidx];
		ll rangel =  node.l, ranger = node.r;
		if(l > ranger || r < rangel) return default_val;
		if(l <= rangel && r>=ranger) {
			if(node.lazy==false) {
				debug(rangel,ranger,node.val);		
				return node.val;
			}
			else { 
				T ret = node.val;
				query_val_policy(ret, query_lazy_policy(node.r-node.l+1,node.lazy_val));
				debug(rangel,ranger,ret);		
				return ret;
			}
		}
		T ret=default_val;
		assert(node.lidx != -1 && node.ridx!=-1);
		query_val_policy(ret,_query(l,r,node.lidx));
		query_val_policy(ret,_query(l,r,node.ridx));
		if(node.lazy)
			query_val_policy(ret, query_lazy_policy((ranger-rangel+r-l-max(node.r,r)+min(node.l,l)+1),node.lazy_val));
		debug(rangel,ranger,ret);		
		return ret;
	}
};

void solve(){
	cin >> n >> m;
	SegmentTree<ll, 0ll> st(0,n-1,n<<2,
			[](ll &a, ll b){
			a+=b;
			},
			[](ll &a, ll b){
				a+= b;
			},
			[](int a, ll b)->ll{
			return a*b;
			});
	for (int i = 0; i < n; ++i){ 
		cin >> p[i];
		st.update(i,p[i]);
	}
	for(int i=0;i<m;++i){
		int op; cin >> op;
		int x,y,k;
		cin >> x >>y; --x;--y;
		if(op==1){
			cin >> k;
			st.range_update(x,y,k);
		}
		else{
			cout<<st.range_query(x, y)<<endl;
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
