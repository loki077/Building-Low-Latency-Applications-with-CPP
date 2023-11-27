#include <cstdio>  // For printf function

// Base class using runtime polymorphism
class RuntimeExample {
public:
  // Virtual function to be overridden by derived classes
  virtual void placeOrder() {
    printf("RuntimeExample::placeOrder()\n");
  }
};

// Derived class overriding the virtual function of the base class
class SpecificRuntimeExample : public RuntimeExample {
public:
  // Overridden function
  void placeOrder() override {
    printf("SpecificRuntimeExample::placeOrder()\n");
  }
};

// Base class using compile-time polymorphism (CRTP)
template<typename actual_type>
class CRTPExample {
public:
  // Function that calls the actualPlaceOrder function of the derived class
  void placeOrder() {
    static_cast<actual_type *>(this)->actualPlaceOrder();
  }

  // Default implementation of actualPlaceOrder
  void actualPlaceOrder() {
    printf("CRTPExample::actualPlaceOrder()\n");
  }
};

// Derived class providing its own implementation of actualPlaceOrder
class SpecificCRTPExample : public CRTPExample<SpecificCRTPExample> {
public:
  // Overridden function
  void actualPlaceOrder() {
    printf("SpecificCRTPExample::actualPlaceOrder()\n");
  }
};

int main(int, char **) {
  // Create an instance of SpecificRuntimeExample and call placeOrder
  RuntimeExample *runtime_example = new SpecificRuntimeExample();
  runtime_example->placeOrder();

  // Create an instance of SpecificCRTPExample and call placeOrder
  CRTPExample <SpecificCRTPExample> crtp_example;
  crtp_example.placeOrder();

  return 0;
}