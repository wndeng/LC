#include <iostream>
#include <string>
#include <getopt.h>
#include <assert.h>
#include <iomanip>

using namespace std;

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


void check(int n[], int size, int target) { // Regular DP
    int **m = new int*[size+2];
    for(int i = 0; i < size + 2; i++) {
        m[i] = new int[target+2];
    }

    for(int i = 0; i < size; i++) {
    	m[i + 2][0] = n[i];
    }

    for(int i = 2; i <= target + 1; i++) {
    	m[0][i] = i - 1;
    }

    for(int i = 1; i <= size + 1; i++) {
    	m[i][1] = 1;
    }


    for(int i = 2; i < size + 2; i++) {
    	for(int j = 2; j < target + 2; j++) {
    		if(j - 1 - n[i-2] == 0) { // If individual value equal target then obviously the subset is possible
    			m[i][j] = 1;
    		}
    		if(j - 1 - n[i-2] > 0) { // If current target higher than current value, then a subset is only possible if current target - current value is possible from combination of previous values,
    								// or current target itself is possible without current value from previous values
    			m[i][j] = max(m[i-1][j - n[i-2]], m[i-1][j]);
    		}
    		if(j - 1 - n[i-2] < 0) { // If current value is higher than current target, then it cannot be included and thus current target is only possible from combination of previous values 
    			m[i][j] = m[i-1][j];
    		}
    	}
    }

    for(int i = 0; i < size + 2; i++) {
    	for(int j = 0; j < target + 2; j++) {
    		cout << setw(3) << m[i][j] << " ";
    	}
    	cout << endl;
    }

    delete [] m;
    
}

void check2(int n[], int size, int target) { // Space optimized
	cout << setw(3) << 0 << " ";
	for(int i = 0; i < target + 1; i++) {
		cout << setw(3) << i << " ";
	}
	cout << endl;

	int *m = new int[target+1]; // weight 0 to target

	m[0] = 1; // weight 0 is always possible by picking 0 items
	for(int i = 1; i < target + 1; i++) { // All other weight is not possible with 0 items
		m[i] = 0;
	}

	cout << setw(3) << 0 << setw(3) << " " << 1 << " "; // To match prev output
	for(int i = 0; i < target; i++) {
		cout << setw(3) << 0 << " ";
	}
	cout << endl;

	for(int i = 1; i < size + 2; i++) {
		cout << setw(3) << n[i-1] << " ";

		for(int j = target; j > 0; j--) {
			if(j - n[i-1] == 0) {
				m[j] = 1;
			}
			if(j - n[i-1] > 0) {
				m[j] = max(m[j], m[j - n[i-1]]); // old m[j] = m[i-1][j], since same array is looped throughout the 'i's
			}
			if(j - n[i-1] < 0) {  // m[j] = m[i-1][j] so m[j] doesn't change

			}
		}

		for(int k = 0; k < target + 1; k++) {
			cout << setw(3) << m[k] << " ";
		}

		cout << endl;
	}
}

int main() {
	int x[4] = {1, 3, 6, 8};
	int target = 11;
	check(x, 4, target);
	cout << endl;
	check2(x,3, target);
    return 0;
}