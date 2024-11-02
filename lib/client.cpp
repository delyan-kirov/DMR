#include <iostream>

void foo_cb() { std::cout << "INFO: foo_cb called inside the client\n"; }

void foo_fcn() {}

int main(void) {
  std::cout << "Hello from client\n";
  foo_fcn();
}
