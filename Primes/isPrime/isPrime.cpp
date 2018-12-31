#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>
#include <string.h>
#include <chrono>
#include <limits.h>

uint32_t powMod(uint32_t base, uint32_t power, uint32_t mod);
bool witness(uint32_t w, uint32_t k, uint32_t s, uint32_t mod);
bool isPrime(uint32_t n);

bool witness(uint32_t w, uint32_t k, uint32_t s, uint32_t mod) {
    uint32_t cur = powMod(w, k, mod);
    if(cur == 1) return true;
    for(uint32_t i = 0; i < s-1; i++) {
        cur = (cur * cur) % mod;
        if(cur == mod-1) return true;
    }
    return cur == mod-1;
}

bool isPrime(uint32_t n) { // Deterministic Rabin Miller Algorithm with witnesses 2, 7, 61, valid for all uint32_t numbers

    if(n == 2 || n == 3 || n == 7 || n == 61) return true;
    else if(n <= 2 || (n & 1) == 0) return false;

    uint32_t k = n-1, s = 0;
    while (k % 2 == 0) {
        k >>= 1;
        s += 1;
    }
    if(n < 2 || !witness(2, k, s, n) || !witness(7, k, s, n) || !witness(61, k, s, n)) return false;
    return true;
}

uint32_t powMod(uint32_t base, uint32_t power, uint32_t mod) { // Fast power mod based on binary modular exponentiation

    bool b = power & 1;
    uint32_t acc = b ? base % mod : 1, cur = base % mod;

    while(power != 0) {
        power >>= 1;
        b = power & 1;
        cur = (cur * cur) % mod;
        if(b) acc = (acc * cur) % mod;
    }
    return acc;
}

int main(int argc, char** argv)
{
    uint32_t n = 8011;
    if(isPrime(n)) std::cout << n << " is prime\n";
    else std::cout << n << " is composite\n";
}