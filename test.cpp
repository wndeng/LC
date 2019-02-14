#include "util.h"

using namespace std;

int ref(vector<int>& tmp) { // Brute Force
	int count = 0, size = tmp.size();
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < i; ++j) {
			if(tmp[j] > tmp[i]) ++count;
		}
	}
	return count;
}

int invCount(vector<int>& tmp, int i , int j) {
	if(i == j) return 0;
	int mid = i + (j-i)/2, l = 0, r = 0, count = 0;
	count += invCount(tmp, i, mid);
	count += invCount(tmp, mid+1, j);
	vector<int> left(tmp.begin()+i, tmp.begin()+mid+1), right(tmp.begin()+mid+1, tmp.begin()+j+1);
	left.push_back(INT32_MAX); right.push_back(INT32_MAX);

	for(int iter = i; iter <= j; ++iter) {
		if(left[l] <= right[r]) tmp[iter] = left[l++];
		else {
			tmp[iter] = right[r++];
			count += max(0, mid + r - iter);
		}
	}
	return count;
}


bool binarySearch(const vector<int>& tmp, int target) {
	int low = 0, high = tmp.size()-1, mid;
	while(low <= high) {
		mid = low + (high-low)/2;
		int det = tmp[mid];
		if(det == target) return true;
		else if(det < target) low = mid+1;
		else high = mid-1;
	}
	return false;
} // Invariant: Solution must have index between low and high. 

bool binarySearchR(const vector<int>& tmp, int target, int i, int j) {
	int mid = i + (j-i)/2, det = tmp[mid];
	if(i > j) return false;
	if(det == target) return true;
	else if(det < target) return binarySearchR(tmp, target, mid+1, j);
	else return binarySearchR(tmp, target, i, mid-1);
} // T(n) = T(n/2) + c --> T(n) = log(n);


bool isValidSerialization(string preorder) {
    stringstream ss(preorder);
    vector<string> p;
    string t;
    while(getline(ss, t, ',')) p.push_back(t);
    int size = p.size(), i = 0;
    if(size % 2 == 0) return false;
    stack<string> tmp;
    while(i < size) {
        while(p[i] != "#") {
        	tmp.push(p[i++]);
        }
        while(p[i] == "#") {
            if(tmp.empty()) return i == size - 1;
            tmp.pop();
            ++i;
        }
    }
    
    return tmp.empty();
}

int main() {
	// for(int i = 0; i < 99; ++i) {
	// 	vector<int> tmp;
	//     for(int i = 0; i < rand() % 999; ++i) tmp.push_back(rand() % 277);
	//     random_shuffle(tmp.begin(), tmp.end());
	//     assert(ref(tmp) == invCount(tmp, 0, tmp.size()-1));
	// }

	// vector<int> tmp1 = {1,2,3,4,5,6,6,6,7,8,9,10};

	// for(int i = 0; i <= 11; ++i) cout << binarySearchR(tmp1, i, 0, tmp1.size()-1);

	// cout << isValidSerialization("9,#,9,1,1,1,#,9,#,#,9,#,#,#,9,2,#,#,#") << endl;
	vector<int> tmp = {1};
	int n = 2;
	for(int i = 1; i <= 10; ++i) {
		tmp.push_back(4*tmp[i-1] + n*n*i);
		n <<= 1;
	}
	print(tmp);

}