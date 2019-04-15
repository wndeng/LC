#include "util.h"

using namespace std;

bool stringMatch(string A, string B) { // A is matching string, B is pattern

    int BSize = B.size(), ASize = A.size();

    vector<int> lps(BSize, 0);
    
    lps[0] = 0;
    int len = 0, i = 1, j = 0;
    while(i < BSize) {
        if(B[i] == B[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    i = 0;
    
    while(i < ASize) {
        if(B[j] == A[i]) {
            i++;
            j++;
        }
        if(j == BSize) return true;

        else if(i < ASize && B[j] != A[i]) {
            if(j != 0) j = lps[j-1];
            else ++i;
        }
        
    }
    
    return false;
    
}

int main() {
	if(stringMatch("aaaaabc", "abc")) cout << "True" << endl;
	else cout << "False" << endl;
}