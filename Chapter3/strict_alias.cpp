#include <cstdio>   // For printf function
#include <cstdint>  // For uint64_t

int main() {
  double x = 100;  // Initialize a double variable x with value 100
  const auto orig_x = x;  // Make a constant copy of x

  // Create a pointer x_as_ui that points to the memory location of x, but treats the contents as a uint64_t
  auto x_as_ui = (uint64_t *) (&x);  

  // Perform a bitwise OR operation on the uint64_t representation of x with the hexadecimal number 0x8000000000000000
  *x_as_ui |= 0x8000000000000000;  

  // Print the original value of x (orig_x), the modified value of x, and the memory addresses of x and x_as_ui
  printf("orig_x:%0.2f x:%0.2f &x:%p &x_as_ui:%p\n", orig_x, x, &x, x_as_ui);  
}