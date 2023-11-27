#include <cstdio>   // For printf function
#include <cstdint>  // For fixed-width integer types
#include <cstdlib>  // For rand function

// Enum class to represent the side of a trade
enum class Side : int16_t { BUY = 1, SELL = -1 };

int main() {
  // Randomly select a side for the trade
  const auto fill_side = (rand() % 2 ? Side::BUY : Side::SELL);
  const int fill_qty = 10;  // Quantity for the trade
  // Print the side and quantity of the trade
  printf("fill_side:%s fill_qty:%d.\n", (fill_side == Side::BUY ? "BUY" : (fill_side == Side::SELL ? "SELL" : "INVALID")), fill_qty);

  { // with branching
    // Initialize quantities and position
    int last_buy_qty = 0, last_sell_qty = 0, position = 0;

    // Update position and quantities based on the side of the trade
    if (fill_side == Side::BUY) { position += fill_qty; last_buy_qty = fill_qty;
    } else if (fill_side == Side::SELL) { position -= fill_qty; last_sell_qty = fill_qty; }

    // Print position and quantities
    printf("With branching - position:%d last-buy:%d last-sell:%d.\n", position, last_buy_qty, last_sell_qty);
  }

  { // without branching
    // Initialize quantities and position
    int last_qty[3] = {0, 0, 0}, position = 0;

    // Lambda function to convert Side to int
    auto sideToInt = [](Side side) noexcept { return static_cast<int16_t>(side); };

    // Convert fill_side to int
    const auto int_fill_side = sideToInt(fill_side);
    // Update position and quantities based on the side of the trade
    position += int_fill_side * fill_qty;
    last_qty[int_fill_side + 1] = fill_qty;

    // Print position and quantities
    printf("Without branching - position:%d last-buy:%d last-sell:%d.\n", position, last_qty[sideToInt(Side::BUY) + 1], last_qty[sideToInt(Side::SELL) + 1]);
  }
}