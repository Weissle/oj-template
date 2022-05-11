//https://www.luogu.com.cn/problem/solution/P3367
#include<bits/stdc++.h>

using namespace std;

int n,m,l,r;

struct DSU{
	vector<int> p;
	// assert  (x+offset >= 0);
	int offset;
	DSU(){}
	DSU(int n,int offset_=0):p(n,-1),offset(offset_){}
	int find(int x){
		x += offset;
		int fat=x;
		while(p[fat]!=-1) fat = p[fat];
		while(x!=fat){
			int tmp = p[x];
			p[x] = fat;
			x = tmp;
		}
		return fat-offset;
	}
	void combine(int x,int y){
		x += offset; y+= offset;
		int x_fat = find(x), y_fat = find(y);
		if(x_fat!=y_fat){
			p[x_fat] = y_fat;
		}
	}
};

void solve(){
	int n,m; cin >> n >> m;
	DSU dsu(1e4);
	for (int i = 0; i < m; ++i){ 
		int a,b,c;cin>>a>>b>>c;
		if(a==1) dsu.combine(b, c);
		else cout<< (dsu.find(b)==dsu.find(c)? 'Y' : 'N')<<endl;
	}
		
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
