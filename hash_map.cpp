#include <iostream>
#include <vector>
#include <cstdlib>
#include "hash_map.h"
using namespace std;
typedef long long ll;

int hash_map::hash(int key) {
	srand(key);
	return rand()*5/3;
}

int& hash_map::operator[](int key) {
	size++;
	if (a.size() == 0) {
		for (int i = 0; i < 1; i++) {
			a.push_back({  });
		}
		a[hash(key) % a.size()].push_back({ key,0 });
	}
	int n = hash(key) % a.size();
	for (int i = 0; i < a[n].size(); i++) {
		if (a[n][i][0] == key) {
			return a[n][i][1];
		}
	}
	if (size == a.size()) {
		vector<vector<vector<int>>> b;
		for (int i = 0; i < n * 2 + 2; i++, b.push_back({}));
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a[i].size(); j++) {
				b[hash(a[i][j][0]) % b.size()].push_back(a[i][j]);
			}
		}
		a = b;
		a[hash(key) % a.size()].push_back({ key,0 });
		return a[hash(key) % a.size()][a[hash(key) % a.size()].size() - 1][1];
	}
	a[hash(key) % a.size()].push_back({ key,0 });
	return a[hash(key) % a.size()][a[hash(key) % a.size()].size() - 1][1];
}

void hash_map::del(int key) {
	size--;
	int n = hash(key) % a.size();
	for (int i = 0; i < a[n].size(); i++) {
		if (a[n][i][0] == key) {
			a[n].erase(a[n].begin() + i);
			return;
		}
	}
	cout << key << "����hash_map��";
	abort();
}

bool hash_map::search(int key) {
	int n = hash(key) % a.size();
	for (int i = 0; i < a[n].size(); i++) {
		if (a[n][i][0] == key) {
			return true;
		}
	}
	return false;
}

vector<int> hash_map::get_key(void) {
	vector<int> key_list;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			key_list.push_back(a[i][j][0]);
		}
	}
	return key_list;
}
