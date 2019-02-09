#include "util.h"

void partition(vector<int>& tmp, int det, int left, int right, int& i, int& j) {
	int mid = i = left; j = right;
	while(mid <= j) {
		if(tmp[mid] < det) swap(tmp[i++], tmp[mid++]);
		else if(tmp[mid] > det) swap(tmp[mid], tmp[j--]); 
		else ++mid;
	}
	--i; ++j;
}

int qs(vector<int>& tmp, int pos, int i, int j) { // left & right inclusive.
	if(i == j) return tmp[i];
	if(j - i == 1) {
		if(tmp[i] > tmp[j]) swap(tmp[i], tmp[j]);
		if(pos == i) return tmp[i];
		return tmp[j];
	}

	int m = i + (j-i)/2, boundLeft, boundRight;
	if(tmp[i] > tmp[m]) swap(tmp[i], tmp[m]);
	if(tmp[m] > tmp[j]) swap(tmp[m], tmp[j]);
	if(tmp[i] > tmp[m]) swap(tmp[i], tmp[m]);
	partition(tmp, tmp[m], i, j, boundLeft, boundRight);
	if(pos > boundLeft) {
		if(pos >= boundRight) return qs(tmp, pos, boundRight, j);
		return tmp[m];
	}
	return qs(tmp, pos, i, boundLeft);
}


int quickSelect(vector<int>& tmp, int pos) { // 0 indexing for pos
	return qs(tmp, pos, 0, tmp.size()-1);
}

int main() {
    std::vector<int> tmp = {1, 3, 5, 1, 6, 2, 3, 6, 2, 3, 5, 1, 2, 3, 5};
    print(tmp);
    sort(tmp.begin(), tmp.end());
    print(tmp);
    int size = tmp.size();
    for(int i = 0; i < size; ++i) cout << quickSelect(tmp, i) << " ";
    cout << endl;

}