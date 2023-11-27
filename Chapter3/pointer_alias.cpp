#include <cstdio> //for printf 
// Function that copies the value pointed by 'b' 
// into each element of the array 'a'
void func(int *a, int *b, int n) {
  for (int i = 0; i < n; ++i) {
    a[i] = *b;
  }
}

// Similar function to 'func', but with 'restrict' 
// keyword which tells the compiler that pointers 'a' and 'b' do not overlap
void func_restrict(int *__restrict a, int *__restrict b, int n) {
  for (int i = 0; i < n; ++i) {
    a[i] = *b;
  }
}

int main() {
  int a[10], b;  // Declare an array 'a' of size 10 and an integer 'b'
  printf("address b %p \n", &b);
  printf("address a %p \n", &a);
  // Call 'func' with 'a', address of 'b', and 10 as arguments
  func(a, &b, 10);
  
  // Call 'func_restrict' with 'a', address of 'b', and 10 as arguments
  func_restrict(a, &b, 10);
}