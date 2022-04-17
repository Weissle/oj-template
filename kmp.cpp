// https://www.luogu.com.cn/problem/P3375
#include<bits/stdc++.h>

using namespace std;

using ll = long long;

template<typename S>
struct KMP{
	vector<int> next;
	vector<int> match;
	void get_next(S &s){
		int n=s.size();
		next.resize(n); next[0] = 0;
		for(int i=1;i<n;++i){
			int j = next[i-1];
			while(j && s[j] != s[i]) j = next[j-1];
			if(s[i] == s[j]) next[i] = j+1;
		}
	}

	void get_match(S &s1, S &s2){
		get_next(s2);
		int n = s1.size(), m = s2.size();
		match.resize(n);
		match[0] = (s1[0]==s2[0]);
		for(int i=1;i<n;++i){
			int j = match[i-1];
			if(j==m) j = next[j-1];
			while(j && s1[i]!=s2[j]) j = next[j-1];
			if(s1[i]==s2[j]) ++j;
			match[i] = j;
		}
	}
};

void solve_(){
	string s1,s2; cin >> s1 >>s2;
	KMP<string> kmp;
	kmp.get_match(s1,s2);
	for(int i=0;i<s1.size();++i){
		if(kmp.match[i] == s2.size()) cout<<i-s2.size()+2<<endl;
	}
	for(auto c:kmp.next){
		cout<<c<<' ';
	}
}

void solve(){
	string s1,s2; cin >> s1 >>s2;
	string s = s2+"#"+s1;
	KMP<string> kmp;
	kmp.get_next(s);
	for(int i=0;i<s1.size();++i){
		if(kmp.next[i+s2.size()+1] == s2.size()) cout<<i-s2.size()+2<<endl;
	}
	for(int i=0;i<s2.size();++i){
		cout<<kmp.next[i]<<' ';
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int t=1;
	//cin >> t;
	while(t--){
		solve();
	//	solve_();
	}

	return 0;
}