#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>
#include <string.h>
#include <chrono>
#include <limits.h>

#define TIMER std::chrono::high_resolution_clock

#define TIME_DIFF std::chrono::duration<double>

#define show(title, x) std::cout << title << ": " << x << std::endl;

template<typename T>
void showVec(const T& t) {
	for(auto n :t) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
}

void sieve(uint32_t n, std::vector<uint32_t> &primes) { // Classical sieve

    std::vector<bool> sieve(n + 1, true);

    if(n == 1) {return;}

    primes.push_back(2);

    for(uint32_t i = 3; i*i <= n; i+= 2) {
        if(sieve[i]) {
            for(uint32_t j = i * i; j <= n; j += i) {
              sieve[j] = false;
            }
        }
    }

    for(uint32_t i = 3; i < sieve.size(); i+=2) {
        if(sieve[i]) {
            primes.push_back(i);
        }
    }
}

int primeCount(int n) { // Segmented sieve

  	if(n < 2) {return 0;}

    uint32_t num = n, size = 75000;
    std::vector<uint32_t> primes, primeRef, factorIndex;

    auto &ref = primeRef;

    if(num < size) {
      sieve(num, ref);
      return primeRef.size();
    }

    sieve(sqrt(num), ref);

    uint32_t start = sqrt(num) + 1, end = sqrt(num) + 1, iter = 1, countIter = start % 2 == 0 ? 1 : 0;

    std::vector<bool> sieveSeg(size, true);

    for(; primeRef[iter]*primeRef[iter] < start; iter++) {
        factorIndex.push_back(((uint32_t) std::ceil((start/ (double) primeRef[iter])) | 1)*primeRef[iter] - start);
        primes.push_back(primeRef[iter]);
    }

    uint32_t count = primeRef.size();

    for(; start <= num; start += size) {
        std::fill(sieveSeg.begin(), sieveSeg.end(), true);
        end = std::min(start + size - 1, num);

        for(; primeRef[iter]*primeRef[iter] <= end && iter < primeRef.size(); iter++) {
            primes.push_back(primeRef[iter]);
            factorIndex.push_back(primeRef[iter]*primeRef[iter] - start);
        }
        
        for(uint32_t i = 0; i < factorIndex.size(); i++) {
            for(; factorIndex[i] < size; factorIndex[i] += 2*primes[i]) {
                sieveSeg[factorIndex[i]] = false;
            }
            factorIndex[i] -= size;
        }

        for(; countIter < std::min(size, end - start + 1); countIter += 2) {
            if(sieveSeg[countIter]) {count++;}
        }
        countIter -= size;
        show("cur count", count);
    }

    return count;
}

int main(int argc, char** argv)
{
    uint32_t x = INT_MAX;
    int count = primeCount(x);
    show("count", count);
}