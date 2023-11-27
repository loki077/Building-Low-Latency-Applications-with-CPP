#include <cstdint>  // For fixed-width integer types

int main() {
  // Define a price as a constant
  const auto price = 10.125; // prices are like: 10.125, 10.130, 10.135...

  // Define the minimum price increment as a constant expression
  constexpr auto min_price_increment = 0.005;

  // Define an integer price, initialized to 0
  // The [[maybe_unused]] attribute suppresses compiler warnings about the variable not being used
  [[maybe_unused]] int64_t int_price = 0;

  // Without strength reduction:
  // Convert the price to an integer by dividing by the minimum price increment
  // This involves a relatively expensive division operation
  int_price = price / min_price_increment;

  // With strength reduction:
  // Calculate the inverse of the minimum price increment as a constant expression
  constexpr auto inv_min_price_increment = 1 / min_price_increment;
  // Convert the price to an integer by multiplying by the inverse of the minimum price increment
  // This involves a relatively cheap multiplication operation
  int_price = price * inv_min_price_increment;
}