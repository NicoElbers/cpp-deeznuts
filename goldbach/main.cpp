#include <algorithm>
#include <bits/chrono.h>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

class Primes {
private:
  int highestValueChecked = 1;

public:
  std::vector<int> primeCache;
  Primes();
  void genPrimes(int);
  bool isPrime(int);
  bool contains(int);
};

Primes::Primes() {
  primeCache.push_back(2);
  primeCache.push_back(3);
}

bool Primes::contains(int n) {
  for (int i = primeCache.size() - 1; i >= 0; --i) {
    if (n == primeCache[i])
      return true;
  }
  return false;
}

bool Primes::isPrime(int n) {
  if (n <= highestValueChecked) {
    return contains(n);
  }

  int i = 0;
  int currentPrime = primeCache[i];
  bool notPrime;
  bool completed = false;
  while (!completed) {
    notPrime = n % currentPrime == 0;
    completed = notPrime || currentPrime * currentPrime > n;

    i++;
    currentPrime = primeCache[i];
  }

  highestValueChecked = n;
  return !notPrime;
}

void Primes::genPrimes(int n) {
  int upperPrimeLimit = (int)(n / 3);
  upperPrimeLimit = upperPrimeLimit << 1;
  primeCache.reserve(upperPrimeLimit);

  for (int i = 7; i <= n; i += 6) {

    if (isPrime(i - 2)) {
      primeCache.push_back(i - 2);
    }
    if (isPrime(i)) {
      primeCache.push_back(i);
    }
  }

  std::cout << primeCache.size() << " primes were calculated under " << n
            << std::endl;
}

class Goldbach {
private:
  int limit = 200000;
  bool debug = 0;
  Primes p;

public:
  Goldbach();
  int ask_settings();
  void print_settings();
  void calculate();
  int getLimit();
};

int Goldbach::getLimit() { return limit; }

int Goldbach ::ask_settings() {
  std::cout << "Till what number would you like to calculate?" << std::endl;
  std::cin >> limit;

  if (limit <= 0) {
    std::cout << "Limit isn't set correctly" << std::endl;
    return -1;
  }

  return 0;
}

Goldbach::Goldbach() { p = Primes(); }

void Goldbach ::print_settings() {
  std::cout << std::endl << "Settings:" << std::endl;
  std::cout << "limit: " << this->limit << std::endl;
  std::cout << std::endl;
}

void Goldbach ::calculate() {
  p.genPrimes(limit);

  std::cout << "Generated primes" << std::endl;

  bool calulated = false;

  for (int num = 4; num <= limit; num += 2) {
    calulated = false;

    for (int i = 0; i <= p.primeCache.size(); ++i) {
      int currentPrime = p.primeCache[i];

      if (p.contains(num - currentPrime)) {
        // std::cout << currentPrime << " + " << num - currentPrime << " = " <<
        // num
        //           << std::endl;
        calulated = true;
        break;
      }
    }

    if (!calulated) {
      std::cout << "FOUND AN ERROR" << std::endl;
      exit(-1);
    }
  }
}

int main(int argc, char *argv[]) {

  Primes p;
  // Goldbach *gb = new Goldbach();
  //
  // gb->ask_settings();
  // gb->print_settings();

  // auto begin = std::chrono::high_resolution_clock::now();

  // gb->calculate();
  p.genPrimes(10000000);

  // auto end = std::chrono::high_resolution_clock::now();
  // auto duration =
  //     std::chrono::duration_cast<std::chrono::milliseconds>(end - begin)
  //         .count();

  // for (int i = 0; i < p.primeCache.size(); i++)
  //   std::cout << p.primeCache[i] << ", ";
  //
  // std::cout << std::endl;

  // std::cout << "Calculation took: " << duration << "ms" << std::endl;

  return 0;
}
