#include "util.h"

using namespace std;

class BinaryIndexTree {
public:
    BinaryIndexTree(vector<int>& s) {
        setVec(s);
    }
    
    BinaryIndexTree() {};

    void setVec(vector<int>& s) {
        size = s.size();
        original = vector<int>(size, 0);
        vec = vector<int>(size+1, 0);
        for(int i = 0; i < s.size(); ++i) update(i, s[i]);
        original = s;
    }
    
    void update(int ind, int n) {
        int val = n - original[ind];
        original[ind] = n;
        ind += 1;
        while(ind <= size) {
            vec[ind] += val;
            ind += ind & (-ind);
        }
    }

    int sumRange(int i, int j) {
        if(j < i || i < 0) return 0;
        if(i == j) return original[i];
        if(i == 0) return getSum(j);
        return getSum(j) - getSum(i-1);
    }

    void print() {
        for(auto &n: vec) cout << n << " ";
        cout << '\n';
    }

private:
    int getSum(int i) {
        i += 1;
        int acc = 0;
        while(i > 0) {
            acc += vec[i];
            i -= i & (-i);
        }
        return acc;
    }
    vector<int> vec;
    vector<int> original;
    int size;
};

int main() {

}