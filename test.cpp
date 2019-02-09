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

int mid = 2;
int size = 6;
inline int virtualIndex(int i) {
    if(i <= mid) return (mid-i)*2;
    return 1 + 2*(size - i - 1);
}

int main() {
    vector<int> tmp = {1, 3, 5, 1, 6, 2, 3, 6, 2, 3, 5, 1, 2, 3, 5};
    for(int i = 0; i <= 5; ++i) {
    	cout << i << " " << virtualIndex(i) << endl;
    }

}