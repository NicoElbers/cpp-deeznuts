#include <iostream>
#include <ostream>

void print(int[], int);
void Input(int[], int);
void lSearch(int[], int, int);

int main() {
  int arr[5];
  Input(arr, 5);
  print(arr, 5);
  lSearch(arr, 5, 3);
  return 0;
}

void print(int A[], int length) {
  std::cout << "The elements of the array are:" << std::endl;
  for (int i = 0; i < length; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}

void Input(int A[], int length) {
  std::cout << "Enter the elements:" << std::endl;
  for (int i = 0; i < length; ++i) {
    std::cout << "Enter element #" << i << ": ";
    std::cin >> A[i];
  }
}

void lSearch(int A[], int length, int data) {
  for (int i = 0; i < length; ++i) {
    if (A[i] == data)
      std::cout << "Found data at #" << i << std::endl;
  }
}
