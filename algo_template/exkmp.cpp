// #define LOCAL

//https://www.luogu.com.cn/problem/P5410
#include<bits/stdc++.h>

using namespace std;

using ll = long long;

template<typename S>
struct EXKMP{
	vector<int> z;
	vector<int> match;
	void get_z(S &s){
		int n=s.size();
		z.resize(n); z[0] = 0;
		int l=0,r=0;
		for(int i=1;i<n;++i){
			if(i<=r) z[i] = min(z[i-l],r-i);
			while(i+z[i]<n && s[i+z[i]] == s[z[i]]) ++ z[i];
			if(i+z[i]-1>r){
				l=i; r=i+z[i]-1;
			}
		}
	}

	void get_match(S &s1, S &s2){
		get_z(s2);
		int n = s1.size(), m = s2.size();
		match.resize(n);
		match[0] = (s1[0]==s2[0]);
		int l=0,r=0;
		for(int i=0;i<n;++i){
			if(i<=r) match[i] = min(z[i-l],r-i);
			while(i+match[i]<n && match[i]<m && s1[i+match[i]] == s2[match[i]]) ++ match[i];
			if(match[i]+i-1>r){
				l = i; r = match[i]+i-1;
			}
		}
	}
};

void solve_(){
	string s1,s2; cin >> s1 >>s2;
	EXKMP<string> exkmp;
	exkmp.get_match(s1,s2);
	ll ans=0;
	for(ll i=1;i<s2.size();++i){
		ans ^= ll(i+1)*(exkmp.z[i]+1);
	}
	ans ^= s2.size()+1;
	cout<<ans<<endl;
	ans =0;
	for(ll i=0;i<s1.size();++i){
		ans ^= ll(i+1)*(exkmp.match[i]+1);
	}
	cout<<ans<<endl;
}

void solve(){
	#ifndef LOCAL
	string s1,s2; cin >> s1 >>s2;
	#else
	auto f = ifstream("tmp.input",ios_base::in);
	string s1,s2;
	f>>s1>>s2;
	f.close();
	#endif
	string s = s2+"#"+s1;
	EXKMP<string> exkmp;
	exkmp.get_z(s);
	ll ans=0;
	for(ll i=1;i<s2.size();++i){
		ans ^= ll(i+1)*(exkmp.z[i]+1);
	}
	ans ^= s2.size()+1;
	cout<<ans<<endl;
	ans=0;
	for(ll i=0;i<s1.size();++i){
		ans ^= ll(i+1)*(exkmp.z[i+s2.size()+1]+1);
	}
	cout<<ans<<endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int t=1;
	//cin >> t;
	while(t--){
		// solve();
		solve_();
	}

	return 0;
}
