#include <bits/stdc++.h>
using namespace std;
void SieveOfEratosthenes(int num) {
  auto begin = std::chrono::high_resolution_clock::now();

  bool pno[num + 1];
  memset(pno, true, sizeof(pno));
  for (int i = 2; i * i <= num; i++) {
    if (pno[i] == true) {
      for (int j = i * 2; j <= num; j += i)
        pno[j] = false;
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin)
          .count();

  cout << duration << "ms" << endl;
}
int main() {
  int num = 1000000;
  // cout << "The prime numbers smaller or equal to " << num << " are: ";
  SieveOfEratosthenes(num);
  return 0;
}
