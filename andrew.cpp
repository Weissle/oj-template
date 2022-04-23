// https://www.luogu.com.cn/problem/P2742
//
#include<bits/stdc++.h>
#include <iomanip>

using namespace std;
using ll = long long;
const int MAXN = 1e5+5;
int n;

using pdd = pair<double,double>;
struct Andrew{
	double check(const pdd &a,const pdd &b,const pdd &c){
		pdd t1(b.first-a.first,b.second-a.second);
		pdd t2(c.first-a.first,c.second-a.second);
		return t1.first*t2.second - t1.second*t2.first;
	}
	vector<pdd> run(vector<pdd> &p){
		int n = p.size();
		if(n<3) return p;
		sort(p.begin(),p.end());
		vector<pdd> ret(n);
		ret[0] = p[0];
		ret[1] = p[1];
		int m = 1;
		for (int i = 2; i < n; ++i){ 
			while( m && check(ret[m-1],ret[m],p[i])<=0) --m;
			ret[++m] = p[i];
		}
		assert(ret[m] == p[n-1]);
		int up_bound = m;
		ret[++m] = p[n-2];
		for(int i=n-3;i>=0;--i){
			while(m > up_bound && check(ret[m-1],ret[m],p[i])<=0) --m;
			ret[++m] = p[i];
		}
		if(m<n)
			ret.erase(ret.begin()+m+1,ret.end());
		return ret;
	}
};

void solve(){
	cin >> n;
	vector<pdd> p(n);
	for (int i = 0; i < n; ++i){ 
		cin>>p[i].first >> p[i].second;
	}
	
	Andrew andrew; 
	auto ans = andrew.run(p);
	double d=0;
	if (ans.size()>=3){
		for(int i=1;i<ans.size();++i){
			d += sqrt(pow(ans[i].first-ans[i-1].first,2) + pow(ans[i].second-ans[i-1].second,2) );
		}
	}
	cout<<d;

}

int main(){

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	cout<<fixed<<setprecision(2);
	int t=1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
