// Define a function to calculate the factorial of a number
// The 'noinline' attribute tells the compiler not to inline this function
auto __attribute__ ((noinline)) factorial(unsigned n) -> unsigned {
  // If n is not zero, return n multiplied by the factorial of (n - 1)
  // This is a recursive call to the factorial function
  // If n is zero, return 1 (because the factorial of 0 is 1)
  return (n ? n * factorial(n - 1) : 1);
}

int main() {
  // Calculate the factorial of 100 and store the result in 'res'
  // The 'volatile' keyword tells the compiler that the value of 'res' can change unexpectedly,
  // so it should not optimize any code based on assumptions about the value of 'res'
  // The 'maybe_unused' attribute tells the compiler not to issue a warning if 'res' is not used
  [[maybe_unused]] volatile auto res = factorial(100);
}