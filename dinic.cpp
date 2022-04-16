// https://www.luogu.com.cn/problem/P3376
//
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAXN = 205;

template<typename T>
struct Edge{
	T from,to,c,f;
	Edge(T from_,T to_,T c_,T f_):from(from_),to(to_),c(c_),f(f_){}
	Edge(){}
};

template<typename T,int M>
struct Dinic{
	int n,m,s,t;
	using E = Edge<T>;
	vector<E> edges;
	vector<int> G[M];
	int level[M];
	T INF = numeric_limits<T>::max()/2;

	void init(int n_=M){
		n = n_;
		for (int i = 0; i < n; ++i) G[i].clear();
		edges.clear();
	}
	void addEdge(int from,int to,int cap){
		edges.push_back(E(from,to,cap,0));
		edges.push_back(E(to,from,0,0));
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool bfs(){
		memset(level,0,sizeof(level));
		queue<int> q; q.push(s); level[s] = 1;
		while(q.size()){
			int tmp = q.front(); q.pop();
			int l = level[tmp];
			for(auto eidx:G[tmp]){
				const E &e= edges[eidx];
				if(level[e.to] || e.c == e.f) continue;
				assert(e.c> e.f);
				level[e.to] = l+1;
				q.push(e.to);
			}
		}
		return level[t];
	}
	T dfs(int x,T a){
		if(x==t || a==0) return a;
		int l = level[x];
		T ret=0;
		for(auto eidx:G[x]){
			E &e = edges[eidx];
			if(level[e.to] != l+1 || e.c == e.f) continue;
			T f = dfs(e.to,min(a,e.c-e.f));
			if(f==0) level[e.to] = 0;
			else{
				e.f += f; edges[eidx^1].f -=f;
				ret += f; a-=f;
			}
		}
		return ret;
	}
	T maxFlow(int s_,int t_){
		s = s_; t = t_;
		T ret=0;
		while(bfs()){
			ret += dfs(s,INF);
		}
		return ret;
	}
};

void solve(){
	Dinic<ll,MAXN> dinic;
	int n,m,s,t;
	dinic.init();
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; ++i){ 
		int a,b,c;  cin>> a >> b >> c;
		dinic.addEdge(a, b, c);
	}
	cout<<dinic.maxFlow(s, t);
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int t=1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
