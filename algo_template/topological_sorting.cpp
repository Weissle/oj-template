#include <bits/stdc++.h>
//https://leetcode.cn/problems/QA2IGt

using namespace std;

vector<int> topological_sorting(vector<int> *G,int n){
	vector<int> indeg(n,0);
	for(int i=0;i<n;++i){
		for(auto nxt:G[i]){
			indeg[nxt]++;
		}
	}
	vector<int> ret;
	queue<int> q;
	for(int i=0;i<n;++i){
		if(indeg[i]==0) q.push(i);
	}
	while(q.size()){
		int tmp = q.front(); q.pop();
		ret.push_back(tmp);
		for(auto nxt:G[tmp]){ 
			indeg[nxt]--;
			if(indeg[nxt]==0) q.push(nxt);
		}
	}
	return ret;
}

class Solution {
	public:
		vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
			vector<vector<int>> G(n);
			for (const auto &one:prerequisites){
				int b = one[0],a=one[1];
				G[a].push_back(b);
			}
			auto ret = topological_sorting(G.data(), n);
			if(ret.size()==n)return ret;
			else return {};
		}
};
