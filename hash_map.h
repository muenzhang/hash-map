#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
#define HASH_MAP
#ifdef HASH_MAP
class hash_map {
private:
	vector<vector<vector<int>>> a;
	int size = 0;
	int hash(int key);
public:
	int& operator[](int key);
	void del(int key);
	bool search(int key);
	vector<int> get_key(void);
};
#endif // HASH_MAP

