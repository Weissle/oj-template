#include<bits/stdc++.h>

using namespace std;

//https://www.luogu.com.cn/problem/P3383
using ll = long long;

//Euler
struct EulerPrime{
	vector<int> prime;
	vector<bool> isprime;
	int cnt;
	void run(int N){
		isprime.clear(); isprime.resize(N+1,true);
		prime.clear(); prime.reserve(N);
		cnt=0;
		isprime[0] = isprime[1] = false;
		for(long long i=2;i<=N;++i){
			if(isprime[i]){
				prime.push_back(i);
				cnt++;
			}
			for(int j=0;j<cnt && prime[j]*i<=N;++j){
				isprime[i*prime[j]] = false;
				if(i%prime[j]==0) break;
			}
		}
	}
};


// sieve of eratosthenes
struct SievePrime{
	vector<int> prime;
	vector<bool> isprime;
	int cnt;
	void run(int N){
		isprime.clear(); isprime.resize(N+1,true);
		prime.clear(); prime.reserve(N);
		cnt=0;
		isprime[0] = isprime[1] = false;
		for(long long i=2;i<=N;++i){
			if(isprime[i]){
				prime.push_back(i); ++cnt;
			}
			int j = i+i;
			while(j<=N){
				isprime[j] = false;
				j+=i;
			}
		}
	}
};

void solve(){
	EulerPrime ep;
	//SievePrime ep;
	int n,q; cin>>n>>q;
	ep.run(n);
	cout<<ep.cnt;
}

void speed_test(){
	SievePrime ep_s;
	EulerPrime ep_e;
	int k=10;
	for(int k=10;k<=1e9+5;k*=10){
		cout<<" N = "<<k<<' ';
		auto t1 = chrono::steady_clock::now();
		ep_s.run(k);
		cout<< "sieve : " <<chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now()-t1).count()/1e6<<" s";
		t1 = chrono::steady_clock::now();
		ep_e.run(k);
		cout<< "euler : " <<chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now()-t1).count()/1e6<<" s\n";
		cout.flush();
	}
	
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	//speed_test();
	//return 0;
	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
