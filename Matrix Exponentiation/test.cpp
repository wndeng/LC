#include <iostream>
#include <string>
#include <getopt.h>
#include <iomanip>

using namespace std;

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

int **mult(int **m, int exp, int dim);

void recursive(int n, int a, int b) { // Regular recursion
    if(n == 1) {
        cout << a << endl;
        return;
    }
    recursive(n-1, b, a + b);
}

void matrix(int n) { // Matrix exponentiation

    int **m = new int*[2]; // T
    for(int i = 0; i < 2; i++) {
        m[i] = new int[2];
    }
    m[0][0] = 0; // T = |0  1|
    m[0][1] = 1; //     |1  1|
    m[1][0] = 1;
    m[1][1] = 1;

    int **acc = mult(m, n-1, 2);

    int *m0 = new int[2]; // T0 = [1 1]'
    m0[0] = 1;
    m0[1] = 1;

    int *sol = new int[2];

    int sum = 0;

    for(int i = 0; i < 2; i++) {
        sum = 0;
        for(int j = 0; j < 2; j++) {
            sum += m0[i] * acc[i][j];
        }
        sol[i] = sum;
    }

    cout << sol[0] << endl;

    delete [] acc;
    delete m0;
    delete [] m;
    delete sol;
    return;

}

int **mult(int **m, int exp, int dim) { // Divide & conquer matrix mult
    int **acc = new int*[dim];
    int sum = 0;
    if(exp == 1) {
        for(int i = 0; i < dim; i++) {
            acc[i] = new int[2];
            for(int j = 0; j < dim; j++) {
                acc[i][j] = m[i][j];
            }
        }
        return acc;
    }
    if(exp == 2) {
        for(int i = 0; i < dim; i++) {
            acc[i] = new int[dim];
            for(int j = 0; j < dim; j++) {
                sum = 0;
                for(int k = 0; k < dim; k++) {
                    sum += m[i][k] * m[k][j];
                }
                acc[i][j] = sum;
            }
        }
        return acc;
    }
    else {
        int mid = exp/2;
        int **acc1 = mult(m, mid, dim);
        int **acc2 = mult(m, exp - mid, dim); 
        for(int i = 0; i < dim; i++) {
            acc[i] = new int[dim];
            for(int j = 0; j < dim; j++) {
                sum = 0;
                for(int k = 0; k < dim; k++) {
                    sum += acc1[i][k] * acc2[k][j];
                }
                acc[i][j] = sum;
            }
        }
        delete [] acc1;
        delete [] acc2;
        return acc;
    }
    delete acc;
    return NULL;
}

int main() { // Testing with calculating nth Fibonacci number
	recursive(30, 1, 1); // Testing with 30th Fib #
	matrix(30);
    return 0;
}