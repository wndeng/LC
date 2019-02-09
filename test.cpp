#include <iostream>
#include <string>
#include <getopt.h>
#include <assert.h>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <queue>

using namespace std;

int qs(vector<int>& tmp, int pos) {
	return _qs(tmp, pos, 0, tmp.size()-1);
}

_qs(vector<int>& tmp, int pos, int i, int j) {
	int l = tmp[i], j = tmp[j], m = tmp[i + (j-i)/2];
	
}

_partition(vector<int>& tmp, int mid, int i, int j) {

}

int main() {
    vector<int> tmp = {1, 3, 5, 1, 6, 2, 3, 6, 2, 3, 5, 1, 2, 3, 5};

}