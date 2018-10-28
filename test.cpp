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

int main() {
    cout << "hello world!" << endl;
    return 0;
}