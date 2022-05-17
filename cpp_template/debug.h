#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void debug_out(){ cerr << endl; }

inline string to_string(string s) { return '"' + s + '"'; }

inline string to_string(const char *s) { return to_string(string(s)); }

template<typename A, typename B>
string to_string(pair<A, B> p) { return "<" + to_string(p.first) + "," + to_string(p.second) + ">"; }

inline string to_string(bool b) { return (b ? "true" : "false"); }

template<typename T>
string to_string(T p){
	string ret = "[";
	bool first = true;
	for (const auto &one:p){
		if(first)first=false;
		else ret.push_back(',');
		ret += to_string(one);
	}
	ret.push_back(']');
	return ret;
}

template<typename T,typename... Other>
void debug_out(T val, Other... other){
	cerr<< " " << to_string(val);
	debug_out(other...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
