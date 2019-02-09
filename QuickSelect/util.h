#ifndef UTIL_H
#define UTIL_H

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

using namespace std;

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "[ "; 
    for (const auto &n: v) os << n << " "; 
    os << "]"; 
    return os; 
}

#define print(v) cout << #v << ": " << v << endl;

#endif