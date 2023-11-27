#include <cstdio>
#include <vector>

struct Order {
  int id;
  double price;
};

class InheritanceOrderBook : public std::vector<Order> {
};

class CompositionOrderBook {
  std::vector<Order> orders_; // Private member variable to store orders

public:
  auto size() const noexcept {
    return orders_.size(); // Return the size of the order book
  }
};

int main() {
  InheritanceOrderBook i_book; // Create an instance of InheritanceOrderBook
  CompositionOrderBook c_book; // Create an instance of CompositionOrderBook

  printf("InheritanceOrderBook::size():%lu CompositionOrderBook:%lu\n", i_book.size(), c_book.size()); // Print the sizes of the two order books
}